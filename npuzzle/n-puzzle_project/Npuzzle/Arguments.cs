using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace Npuzzle
{
    public class Arguments
    {
        public bool Generate = false;
        public bool Unsolvable = false;
        public bool Inline = false;
        public bool Help;
        public bool Debug = false;
        public bool Run = false;
        public int Size = 3;
        public int Heuristic = 1;
        public int Algo = 1;

        public Arguments(string[] arguments)
        {
            Generate = MustGenerate(arguments);
            Unsolvable = MustBeUnsolvable(arguments);
            Inline = MustBeInline(arguments);
            Help = MustShowHelp(arguments);
            Debug = MustShowDebug(arguments);
            Run = MustRunAlgorithm(arguments);
            Size = TaquinSize(arguments);
            Heuristic = HeuristicNumber(arguments);
            Algo = Algorithm(arguments);
        }

        private bool MustGenerate(string[] arguments)
        {
            return ((arguments.Contains("-generate") || arguments.Contains("-g") ? true : false));
        }

        private bool MustBeUnsolvable(string[] arguments)
        {
            return ((arguments.Contains("-unsolvable") || arguments.Contains("-u") ? true : false));
        }

        private bool MustBeInline(string[] arguments)
        {
            return ((arguments.Contains("-inline") || arguments.Contains("-i") ? true : false));
        }

        private bool MustShowHelp(string[] arguments)
        {
            return ((arguments.Contains("-help") || arguments.Contains("-h") ? true : false));
        }

        private bool MustShowDebug(string[] arguments)
        {
            return ((arguments.Contains("-debug") || arguments.Contains("-d") ? true : false));
        }

        private bool MustRunAlgorithm(string[] arguments)
        {
            return ((arguments.Contains("-run") || arguments.Contains("-r") ? true : false));
        }

        private int TaquinSize(string[] arguments)
        {
            for(int i = 0; i < arguments.Count() - 1; i++)
                if (arguments[i] == "-size")
                {
                    try
                    {
                        return (Int32.Parse(arguments[i + 1]));
                    }
                    catch (Exception)
                    {
                        throw new ExceptionInvalidSize("Invalid argument after -size");
                    }
                }
            return 3;
        }

        private int HeuristicNumber(string[] arguments)
        {
            for(int i = 0; i < arguments.Count() - 1; i++)
                if (arguments[i] == "-heuristic")
                {
                    try
                    {
                        return (Int32.Parse(arguments[i + 1]));
                    }
                    catch (Exception)
                    {
                        throw new ExceptionInvalidSize("Invalid argument after -heuristic");
                    }
                }
            return 1;
        }
        
        private int Algorithm(string[] arguments)
        {
            for (int i = 0; i < arguments.Count() - 1; i++)
                if (arguments[i] == "-algorithm")
                {
                    try
                    {
                        return (Int32.Parse(arguments[i + 1]));
                    }
                    catch (Exception)
                    {
                        throw new ExceptionInvalidSize("Invalid argument after -algorithm");
                    }
                }
            return 1;
        }

        public void Display(List<string> arguments)
        {
            Console.WriteLine($"Nombre arguments: {arguments.Count()}");
            Console.WriteLine($"Generate: {Generate}");
            Console.WriteLine($"Unsolvable: {Unsolvable}");
            Console.WriteLine($"Inline: {Inline}");
            Console.WriteLine($"Help: {Help}");
            Console.WriteLine($"Size: {Size}");
            Console.WriteLine($"Heuristic: {Heuristic}");
            Console.WriteLine($"Algo: {Algo}");
        }
    }
}