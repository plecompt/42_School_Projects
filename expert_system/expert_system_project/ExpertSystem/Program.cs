using System;
using System.IO;

namespace ExpertSystem
{
    public class ExpertSysteme
    {
        static void Main(string[] args)
        {
            bool debug = false;

            if (args.Length == 0)
            {
                Console.WriteLine("Usage: ./expertsystem testfile");
                return;
            }
            else if (args.Length >= 1 && args.Length < 3)
            {
                try
                {
                    if (args.Length > 1)
                        debug = args[1] == "-d" ? true : false;
                    var lines = File.ReadAllLines(args[0]); //ouverture du fichier texte.
                    var lexered = Lexer.CheckThatFile(lines); //check du fichier
                    var datas = Parser.Parse(lexered); //parsing du fichier
                    var results = Solver.Solve(datas.Item1, Facts.ExtractFactsAndQuerries(datas.Item2, "="), Facts.ExtractFactsAndQuerries(datas.Item3, "?"), debug); //solving
                    Display.ShowResults(results); //affichage des results.
                }
                catch (Exception e)
                {
                    Console.WriteLine(e.Message);
                }
            }
        }
    }
}
