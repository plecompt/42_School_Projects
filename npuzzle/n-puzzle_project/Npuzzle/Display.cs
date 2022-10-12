using System;

namespace Npuzzle
{
    public class Display
    {
        public static void ShowTaquin<T>(T[,] taquin, int size)
        {
            Console.WriteLine(size);

            for (int i = 0; i < size; i++)
            {
                Console.WriteLine();
                for (int j = 0; j < size; j++)
                    Console.Write(taquin[i, j] + ((j != size - 1) ? " " : ""));
            }
            Console.WriteLine();
        }
        public static void Help()
        {
            Console.WriteLine("Use -help or -h to show this help message.");
            Console.WriteLine("Usage: ./Npuzzle [-h]");
            Console.WriteLine("Usage: ./Npuzzle pathOfFile [-g][-u][-i][-d][-r][-size argument][-heuristic argument][-algorithm argument]");
            Console.WriteLine();
            Console.WriteLine("List of flags:");
            Console.WriteLine("-help | -h: Show this help message.");
            Console.WriteLine("-generate | -g: Specify that we will generate a npuzlle. Use with -size option to specify the size of the npuzzle. (false by default)");
            Console.WriteLine("-unsolvable | -u: Specify if the generated npuzzle must be unsolvable. (false by default)");
            Console.WriteLine("-inline | -i: Specify if the npuzzle goal must be inline. (123456780) (false by default)");
            Console.WriteLine("-debug | -d: Toggle debug mode. (false by default)");
            Console.WriteLine("-run | -r: Run the algorithm with the generated taquin. Require -g. (false by default)");
            Console.WriteLine();
            Console.WriteLine("List of options:");
            Console.WriteLine("-size X: Specify the size of the generated npuzzle.");
            Console.WriteLine("-heuristic X: Specify the heuristic to use in the specified algorithm. (Manhattan heuristic by default)");
            Console.WriteLine("-algorithm X: Specify the algorythm to use. (Sequential A* by default)");
            Console.WriteLine();
            Console.WriteLine("List of heuristics:");
            Console.WriteLine("1: Manhattan.");
            Console.WriteLine("2: Euclidien.");
            Console.WriteLine("3: Diagonals.");
            Console.WriteLine("4: TilesOutOfRowAndColumn.");
            Console.WriteLine("5: MisplacedTiles.");
            Console.WriteLine();
            Console.WriteLine("List of Algorithms:");
            Console.WriteLine("1: Astar. (Using sequential A*)");
            Console.WriteLine("2: Astar2. (Using a multithreaded A*)");
            Console.WriteLine("3: Astar3. (Using a multicore A* to find the costless solution)");
        }
    }
}