using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace ExpertSystem
{
    public static class Parser
    {
        public static void Error(string message, int num)
        {
            switch (num)
            {
                case 1:
                    throw new ExceptionSyntaxError("ERROR: " + message);
                case 2:
                    throw new BonusError("ERROR: " + message);
                default:
                    break;
            }

        }

        public static Tuple<List<Data>, List<char>, List<char>> Parse(List<Data> lines)
        {
            List<char> facts = new List<char>(); //les facts. 
            List<char> querries = new List<char>(); //les querries. 
            var max = lines.Count;
            int range = 0;
            int i = 0;
            int bracket = 0;
            int trigger;
            int arrowcount = 0;
            int factcount = 0;
            int querriescount = 0;
            Regex alpha = new Regex(@"[A-Z]");
            Regex alphalow = new Regex(@"[a-z]");
            Regex end = new Regex(@"[+^|1-2(]");
            Regex operand = new Regex(@"[+^|]");
            Regex arrow = new Regex(@"[1-2]");
            Regex global = new Regex(@"[1-2+^|()!]");


            //test des switchs case
            while (i < max)
            {
                trigger = 0;
                if (alphalow.Match(lines[i].nom.ToString()).Success)
                    Error("Syntax error variable must be uppercase", 1);
                if (end.Match(lines[i].nom.ToString()).Success && lines[i].eol)
                    Error("Syntax error eol", 1);
                if (lines[i].nom.Equals('='))
                {
                    range = i;
                    break;
                }
                if (alpha.Match(lines[i].nom.ToString()).Success)
                    trigger = 1; //Alpha
                else if (operand.Match(lines[i].nom.ToString()).Success)
                    trigger = 2; //Operand
                else if (arrow.Match(lines[i].nom.ToString()).Success)
                    trigger = 3; //Arrow
                else if (lines[i].nom.Equals('!'))
                    trigger = 4; //Negation
                else if (lines[i].nom.Equals('('))
                    trigger = 5; //Bracket ouvrante
                else if (lines[i].nom.Equals(')'))
                    trigger = 6; //Bracket fermante
                switch (trigger)
                {
                    case 1: //Alpha
                        if (!lines[i].eol)
                        {
                            if (operand.Match(lines[i + 1].nom.ToString()).Success)
                                i += 1;
                            else if (arrow.Match(lines[i + 1].nom.ToString()).Success)
                                i += 1;
                            else if (lines[i + 1].nom.Equals(')'))
                            {
                                if (bracket <= 0)
                                    Error("Syntax bracket error 1", 1);
                                else
                                    i += 1;
                            }
                            else
                                Error("Syntax error after fact", 1);
                        }
                        else
                        {
                            if (arrowcount > 1)
                                Error("Syntax error too many implies in one line", 1);
                            if (bracket > 0)
                                Error("Syntax error bracket 4", 1);
                            i += 1;
                            arrowcount = 0;
                        }
                        break;

                    case 2: //Operand
                        if (arrowcount > 0)
                            if (lines[i].nom.Equals('|') || lines[i].nom.Equals('^'))
                                Error("Error bonus OR/XOR non géré en conclusion", 2);
                        if (alpha.Match(lines[i + 1].nom.ToString()).Success)
                            i += 1;
                        else if (lines[i + 1].nom.Equals('!'))
                            i += 1;
                        else if (lines[i + 1].nom.Equals('('))
                            i += 1;
                        else
                            Error("Syntax error after operand", 1);
                        break;

                    case 3: //Arrow
                        if (lines[i].nom.Equals('2'))
                            Error("Error bonnus biconditional non géré", 2);
                        arrowcount += 1;
                        if (bracket > 0)
                            Error("Syntax error bracket 2", 1);
                        if (alpha.Match(lines[i + 1].nom.ToString()).Success)
                            i += 1;
                        else if (lines[i + 1].nom.Equals('!'))
                            i += 1;
                        else if (lines[i + 1].nom.Equals('('))
                            i += 1;
                        else
                            Error("Syntax error after arrow", 1);
                        break;

                    case 4: //Negation
                        if (alpha.Match(lines[i + 1].nom.ToString()).Success)
                            i += 1;
                        else
                            Error("Syntax error after \"!\"", 1);
                        break;

                    case 5: //Bracket ouvrante
                        bracket += 1;
                        if (alpha.Match(lines[i + 1].nom.ToString()).Success)
                            i += 1;
                        else if (lines[i + 1].nom.Equals('!'))
                            i += 1;
                        else if (lines[i + 1].nom.Equals('('))
                            i += 1;
                        else
                            Error("Syntax error after \"(\"", 1);
                        break;

                    case 6: //Bracket fermante
                        if (bracket <= 0)
                            Error("Syntax bracket error 3", 1);
                        else
                        {
                            bracket -= 1;
                            if (!lines[i].eol)
                            {
                                if (operand.Match(lines[i + 1].nom.ToString()).Success)
                                    i += 1;
                                else if (arrow.Match(lines[i + 1].nom.ToString()).Success)
                                    i += 1;
                                else if (lines[i + 1].nom.Equals(')'))
                                    i += 1;
                                else
                                    Error("Syntax error after \")\"", 1);
                            }
                            else
                            {
                                if (arrowcount > 1)
                                    Error("Syntax error too many implies in one line", 1);
                                i += 1;
                                arrowcount = 0;
                            }
                        }
                        break;

                    default:
                        Error("Syntax Error character not found", 1);
                        break;
                }
            }

            List<Data> parsedData = lines.GetRange(0, range);

            // réécriture du while pour fact and querries
            while (i < max)
            {
                if (lines[i].nom.Equals('=') && !lines[i].eol)
                {
                    factcount += 1;
                    facts.Add(lines[i].nom);
                    i += 1;
                    if (i == max)
                        break;
                    while (!lines[i].eol)
                    {
                        if (alpha.Match(lines[i].nom.ToString()).Success)
                        {
                            facts.Add(lines[i].nom);
                            i += 1;
                            if (i == max)
                                break;
                        }
                        else
                            Error("Syntax error only fact must be given during fact init", 1);
                    }
                    if (alpha.Match(lines[i].nom.ToString()).Success)
                    {
                        facts.Add(lines[i].nom);
                        i += 1;
                    }
                }
                else if (lines[i].nom.Equals('=') && lines[i].eol)
                {
                    factcount += 1;
                    facts.Add(lines[i].nom);
                    if (i == max - 1)
                        break;
                    if (lines[i + 1].nom.Equals('?') && lines[i + 1].eol)
                        Error("Syntax error querries must be given", 1);
                    else
                    {
                        if (i == max)
                            break;
                        else
                            i += 1;
                    }
                }
                else
                    Error("Syntax error no fact found", 1);
                if (i == max)
                    break;
                if (lines[i].nom.Equals('?') && !lines[i].eol)
                {
                    querriescount += 1;
                    querries.Add(lines[i].nom);
                    i += 1;
                    if (i == max)
                        break;
                    while (!lines[i].eol)
                    {
                        if (alpha.Match(lines[i].nom.ToString()).Success)
                        {
                            querries.Add(lines[i].nom);
                            i += 1;
                            if (i == max)
                                break;
                        }
                        else
                            Error("Syntax error bad character found in querries", 1);
                    }
                    if (alpha.Match(lines[i].nom.ToString()).Success)
                    {
                        querries.Add(lines[i].nom);
                        i += 1;
                    }
                }
                else if (lines[i].nom.Equals('?') && lines[i].eol)
                    Error("Syntax error querries must be given", 1);
                else
                    Error("Syntax error no querries found", 1);
            }
            if (factcount != querriescount)
                Error("Syntax error equal number of fact and querries must be given", 1);

            return new Tuple<List<Data>, List<char>, List<char>>(parsedData, facts, querries); // on return trois listes
        }
    }
}