using System;
using System.Collections.Generic;
using System.Linq;

namespace ExpertSystem
{
    public static class Solver
    {
        public static void ApplieFacts(IList<Data> parsedData, IList<char> facts)
        {
            foreach (var fact in facts)
                foreach (var data in parsedData)
                    if (data.nom == fact)
                        data.value = true;
        }

        public static void ResetFacts(IList<Data> parsedData)
        {
            foreach (var data in parsedData)
                data.value = false;
        }

        public static void ResetDatas(IList<Data> parsedData, IList<Data> backupDatas)
        {
            parsedData.Clear();
            foreach (var elem in backupDatas)
                parsedData.Add((Data)elem.Clone());
        }

        public static int FindEndOfLine(IList<Data> parsedData, int start)
        {
            int i = start;
            while (parsedData[i].eol == false && i < parsedData.Count - 1)
                i++;
            return (i);
        }

        public static bool ContainsParenthesis(IList<Data> line, int limitLeft, int limitRight)
        {
            for (int i = limitLeft; i < limitRight; i++)
                if (line[i].nom == '(' || line[i].nom == ')')
                    return true;
            return false;
        }

        public static (bool result, int index) ContainsAnd(IList<Data> line, int limitLeft, int limitRight)
        {
            for (int i = limitLeft; i < limitRight; i++)
            {
                if (line[i].nom == '+')
                    return (true, i);
                if (line[i].nom == '1')
                    return (false, -1);
            }
            return (false, -1);
        }

        public static (bool result, int index) ContainsOr(IList<Data> line, int limitLeft, int limitRight)
        {
            for (int i = limitLeft; i < limitRight; i++)
                if (line[i].nom == '|')
                    return (true, i);
            return (false, -1);
        }

        public static (bool result, int index) ContainsXor(IList<Data> line, int limitLeft, int limitRight)
        {
            for (int i = limitLeft; i < limitRight; i++)
                if (line[i].nom == '^')
                    return (true, i);
            return (false, -1);
        }

        public static bool ContainsNot(IList<Data> line, int limitLeft, int limitRight)
        {
            for (int i = limitLeft; i < limitRight; i++)
                if (line[i].nom == '!')
                    return true;
            return false;
        }

        public static (int limitLeft, int limitRight) FindNextCouple(IList<Data> line, bool containsParenthesis, bool containsNot)
        {
            int start = -1;
            int end = -1;

            if (containsNot) //contains ! so inverting
            {
                for (int i = 0; i < line.Count; i++)
                {
                    if (line[i].nom == '!')
                    {
                        start = i;
                        end = i + 1;
                        break;
                    }
                }
            }
            else if (containsParenthesis)  //parenthesis. Return more intriqued ones.
            {
                for (int i = 0; i < line.Count; i++)
                    if (line[i].nom == '(')
                        start = i;
                for (int i = line.Count - 1; i > start; i--)
                    if (line[i].nom == ')')
                        end = i;
            }
            else  //no ! or parenthesis
            {
                if (ContainsAnd(line, 0, line.Count).result)
                    return (ContainsAnd(line, 0, line.Count).index - 1, ContainsAnd(line, 0, line.Count).index + 1);
                else if (ContainsOr(line, 0, line.Count).result)
                    return (ContainsOr(line, 0, line.Count).index - 1, ContainsOr(line, 0, line.Count).index + 1);
                else if (ContainsXor(line, 0, line.Count).result)
                    return (ContainsXor(line, 0, line.Count).index - 1, ContainsXor(line, 0, line.Count).index + 1);
                else
                {
                    for (int i = 0; i < line.Count; i++)
                    {
                        if (line[i].type)
                            if (start == -1)
                                start = i;
                            else
                                end = i;
                        if (start != -1 && end != -1)
                            break;
                    }
                }
            }
            return (start, end);
        }

        public static (int limitLeft, int limitRight) FindNextOperation(IList<Data> line)
        {
            int implie = 0;

            for (int i = 0; i < line.Count; i++)
                if (line[i].nom == '1')
                    implie = i;
            if (implie == 1 && line[0].value == true)
                implie = line.Count();

            return FindNextCouple(line, ContainsParenthesis(line, 0, implie), ContainsNot(line, 0, implie));
        }

        public static (int characterLeft, int characterRight) FindMembersOfCouple(IList<Data> line, int limitLeft, int limitRight)
        {
            if (ContainsParenthesis(line, limitLeft, limitRight)) //si on trouve des parentheses
                return (limitLeft + 1, limitRight - 1);
            else //sinon on est deja dessus
                return (limitLeft, limitRight);
        }

        public static int Operand(IList<Data> line, int characterLeft, int characterRight)
        {
            for (int i = characterLeft; i < characterRight; i++)
            {
                if (line[i].nom == '+')
                    return 0;
                if (line[i].nom == '|')
                    return 1;
                if (line[i].nom == '^')
                    return 2;
                if (line[i].nom == '1')
                    return 3;
            }
            return (-1);
        }

        public static void WriteLine(IList<Data> line, int start = 0)
        {
            for (int i = start; i < line.Count; i++)
            {
                if (line[i].value)
                {
                    Console.ForegroundColor = ConsoleColor.Green;
                    Console.Write(line[i].nom);
                    Console.ForegroundColor = ConsoleColor.White;
                }
                else
                {
                    Console.ForegroundColor = ConsoleColor.Red;
                    if (line[i].nom == '1')
                        Console.Write("=>");
                    else
                        Console.Write(line[i].nom);
                    Console.ForegroundColor = ConsoleColor.White;
                }
                if (line[i].eol == true)
                    break;
            }
            Console.WriteLine();
        }

        public static List<Data> FindNewFacts(IList<Data> line)
        {
            List<Data> newFacts = new List<Data>();
            int implies = 0;

            for (int i = 0; i < line.Count; i++)
                if (line[i].nom == '1')
                    implies = i;

            for (int i = implies; i < line.Count; i++)
                if (line[i].nom >= 'A' && line[i].nom <= 'Z')
                    newFacts.Add(line[i]);

            return (newFacts);
        }

        public static int Process(IList<Data> parsedData, IList<Data> line, int linesDones, List<char> facts, bool debug)
        {
            var newFacts = FindNewFacts(line);
            IList<Data> setFacts = new List<Data>();
            int limitLeft;
            int limitRight;
            int characterLeft;
            int characterRight;
            (limitLeft, limitRight) = FindNextOperation(line);
            (characterLeft, characterRight) = FindMembersOfCouple(line, limitLeft, limitRight);

            if (debug)
                WriteLine(line);

            if (characterRight >= 0) //si on a au moins une opération.
            {
                var tmp = line[characterRight];
                tmp.eol = line[limitRight].eol;

                if (characterRight - characterLeft == 0)
                    tmp.value = Logic.Single(tmp.value, false);
                else if (characterRight - characterLeft == 1)
                    tmp.value = Logic.Single(tmp.value, true);
                else if (characterRight - characterLeft == 2)
                {
                    switch (Operand(line, characterLeft, characterRight))
                    {
                        case 0:
                            tmp.value = Logic.And(line[characterLeft].value, line[characterRight].value);
                            break;
                        case 1:
                            tmp.value = Logic.Or(line[characterLeft].value, line[characterRight].value);
                            break;
                        case 2:
                            tmp.value = Logic.Xor(line[characterLeft].value, line[characterRight].value);
                            break;
                        case 3:
                            setFacts = Logic.Implies(line[characterLeft].value, newFacts, facts);
                            break;
                    }
                }
                if (Operand(line, characterLeft, characterRight) != 3)
                {
                    for (int i = 0; i <= limitRight - limitLeft; i++)
                        parsedData.RemoveAt(limitLeft + linesDones);
                    parsedData.Insert(limitLeft + linesDones, tmp);
                }
                else
                {
                    for (int i = 0; i < line.Count - limitLeft; i++)
                        parsedData.RemoveAt(limitLeft + linesDones);
                    for (int i = 0; i < setFacts.Count; i++)
                        parsedData.Insert(limitLeft + linesDones, setFacts[i]);
                }
            }

            linesDones = linesDones + setFacts.Count();
            return linesDones;
        }

        public static Tuple<string, string, List<string>> CreateResult(IList<char> temporaryFacts, IList<char[]> facts, IList<char[]> querries, int q)
        {
            var answers = new List<string>();

            foreach (var querrie in querries[q])
            {
                if (temporaryFacts.Contains(querrie)) //true
                    answers.Add(querrie + " is TRUE");
                else
                    answers.Add(querrie + " is FALSE");
            }
            return (new Tuple<string, string, List<string>>(new string(facts[q]), new string(querries[q]), answers));
        }

        public static void DeleteParenthesisAfterImplie(IList<Data> line)
        {
            int implie = 0;

            for (int i = 0; i < line.Count; i++)
                if (line[i].nom == '1')
                    implie = i;
            for (int i = implie; i < line.Count; i++)
                if (line[i].nom == '(' || line[i].nom == ')')
                {
                    line.RemoveAt(i);
                    i = implie;
                }
            line[line.Count - 1].eol = true;
        }


        public static List<Tuple<string, string, List<string>>> Solve(IList<Data> parsedData, IList<char[]> facts, IList<char[]> querries, bool debug)
        {
            var results = new List<Tuple<string, string, List<string>>>();
            var backupDatas = new List<Data>();
            var backupFacts = new List<char[]>(facts);
            int linesDones;
            int linesDones2;
            int start;
            int end;
            bool addedFact = false;

            //backup des datas.
            foreach (var elem in parsedData)
                backupDatas.Add((Data)elem.Clone());

            for (int q = 0; q < querries.Count; q++)
            {
                if (debug)
                {
                    Console.Write("For fact(s): ");
                    Console.WriteLine(facts[q]);
                }
                //reset and set the facts
                var temporaryFacts = facts[q].ToList();
                linesDones = 0;

                //reset des datas.
                ResetDatas(parsedData, backupDatas);
                ResetFacts(parsedData);
                ApplieFacts(parsedData, facts[q]);

                //for (int i = 0; i < parsedData.Count ; i++)
                while (parsedData.Count != linesDones)
                {
                    start = linesDones;//nouvelle ligne
                    end = FindEndOfLine(parsedData, start);//on recupere la fin de la ligne
                    var line = parsedData.ToList().GetRange(start, end - start + 1);

                    DeleteParenthesisAfterImplie(line);

                    for (int j = 0; j <= end - linesDones; j++)
                        parsedData.RemoveAt(linesDones);
                    for (int k = line.Count - 1; k >= 0; k--)
                        parsedData.Insert(linesDones, line[k]);

                    linesDones2 = Process(parsedData, line, linesDones, temporaryFacts, debug);

                    if (linesDones2 > linesDones) //sinon on passe à la ligne d'après, on applie le nouveau fact et on retourne à 0 sinon on passe à la ligne d'apres.
                    {
                        for (int i = 0; i < linesDones2 - linesDones; i++)
                            if (parsedData[linesDones + i].value && !temporaryFacts.Contains(parsedData[linesDones + i].nom))//nouveau fact donc on l'applie et on retourne au debut.
                            {
                                if (debug)
                                    Console.WriteLine("Fact {0} added. Starting over.", parsedData[linesDones + i].nom);
                                temporaryFacts.Add(parsedData[linesDones + i].nom);
                                addedFact = true;
                            }
                        if (addedFact) //nouveau fact donc on l'applie et on retourne au debut.
                        {
                            //reset des datas.
                            ResetDatas(parsedData, backupDatas);
                            ResetFacts(parsedData);
                            ApplieFacts(parsedData, temporaryFacts);
                            linesDones = 0;
                            addedFact = false;
                        }
                        else //pas de nouveau fact donc ligne suivante.
                            linesDones = linesDones2;
                    }
                }
                results.Add(CreateResult(temporaryFacts, backupFacts, querries, q));
                if (debug)
                    Console.WriteLine();
            }

            return results;
        }
    }
}
