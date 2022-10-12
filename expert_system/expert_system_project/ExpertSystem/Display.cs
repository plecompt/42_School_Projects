using System;
using System.Collections.Generic;

namespace ExpertSystem
{
    public static class Display
    {
        public static void ShowResults(List<Tuple<string, string, List<string>>> results)
        {
            foreach (var result in results)
            {
                Console.Write("For given facts: =");
                Console.Write(result.Item1);
                Console.Write("\nWith theses querries: ?");
                Console.Write(result.Item2);
                Console.WriteLine();
                foreach (var answer in result.Item3)
                    Console.WriteLine(answer);
                Console.WriteLine();
            }
        }
    }
}
