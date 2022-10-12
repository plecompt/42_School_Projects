using System;
using System.IO;
using System.Diagnostics;
using System.Linq;
using System.Collections.Generic;
using System.Collections.Concurrent;
using System.Threading.Tasks;

namespace Npuzzle
{
    public class Program
    {
        static void Main(string[] args)
        {
            try
            {
                var arguments = new Arguments(args);
                var taquin = new int[arguments.Size, arguments.Size];

                Checker.CheckArguments(arguments);

                // if (arguments.Debug) //temporaire
                //     arguments.Display(args.ToList());

                if (arguments.Help || args.Count() == 0)
                {
                    Display.Help();
                    return ;
                }
                if (arguments.Generate)
                    taquin = Generate.Puzzle(arguments.Size, true, arguments.Unsolvable, arguments.Inline);
                if (arguments.Run || !arguments.Generate)
                {
                    var lexed = new List<string>();
                    var size = 0;
                    int[,] initstate;

                    if (!arguments.Generate)
                    {
                        lexed = Lexer.CheckThatFile(File.ReadLines(args[0]).ToList()); //lexing 
                        (initstate, size) = Parser.ParseThatFile(lexed); //parsing
                    }
                    else
                    {
                        initstate = taquin;
                        size = arguments.Size;
                    }
                    
                    var GoalConfig = Generate.Puzzle(size, false, false, arguments.Inline); //generate goalTaquin
                    
                    if (!Checker.CheckTaquin(initstate, size, arguments.Inline) || GoalConfig.Equals(initstate)) //à verifier
                    {
                        Console.WriteLine($"This {size}-puzzle is not solvable.");
                        return;
                    }
                    
                    var g_indexof0 = Checker.CoordinatesOf(GoalConfig, 0);
                    var i_indexof0 = Checker.CoordinatesOf(initstate, 0);
                    var initialState = new StateNode<int>(initstate, i_indexof0, 0);
                    var finalState = new StateNode<int>(GoalConfig, g_indexof0, 0);
                    var watch = new Stopwatch();
                    var aStar = new AStar<int>(initialState, finalState, 0, arguments.Heuristic, arguments.Debug);
                    var aStar2 = new AStar2<int>(initialState, finalState, 0, arguments.Heuristic, arguments.Debug);
                    var test = new ConcurrentDictionary<int, AStar3<int>>();
                    watch.Start();

                    switch (arguments.Algo)
                    {                        
                        case 1:
                        {
                            aStar.Execute(); 
                            watch.Stop();
                            aStar.Display();
                            break;
                        }
                        case 2:
                        {
                            var tmp = Task.Run(async () => await aStar2.ExecuteAsync()).Result;
                            watch.Stop();
                            aStar2.Display();
                            break;
                        }
                        case 3:
                        {
                            int cs = Int32.MaxValue;
                            int ct = Int32.MaxValue;
                            int open = Int32.MaxValue;
                            int index = 0;
                            Parallel.For(0, 24, new ParallelOptions { MaxDegreeOfParallelism = Environment.ProcessorCount }, (i) =>
                            {
                                test.TryAdd(i, new AStar3<int>(initialState, finalState, 0, arguments.Heuristic, i, arguments.Debug));
                                test[i].Execute();
                                if ((test[i].GetComplexityInTime + test[i].GetComplexityInSize + test[i].GetOpenList) < (cs + ct + open))
                                {
                                   ct = test[i].GetComplexityInTime;
                                   cs = test[i].GetComplexityInSize;
                                   open = test[i].GetOpenList;
                                   index = i;
                                }
                                test[i].Clear();
                            });
                            watch.Stop();
                            test[index].Display(open, ct, cs);
                            break;
                        }
                    }
                    Console.WriteLine("Elapsed miliseconds: {0} ({1})", watch.ElapsedMilliseconds, watch.Elapsed);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.GetType());
                Console.WriteLine(e.Message);
            }
        }
    }
}