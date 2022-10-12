using System;
using System.Collections.Generic;
using System.Linq;

namespace Npuzzle
{
    public static class Generate
    {
        private static int[,] GenerateTaquin(int size, bool inline)
        {
            int x = 1;
            int offset = 0;
            var taquin = new int[size, size];

            if (!inline)
            {
                while (offset != size / 2)
                {
                    //top Line
                    for (int f = offset; f < size - offset; f++)
                        taquin[offset, f] = x++;
                    //right line
                    for (int r = offset + 1; r < size - offset; r++)
                        taquin[r, size - 1 - offset] = x++;
                    //bottom line
                    for (int b = size - 2 - offset; b >= offset; b--)
                        taquin[size - 1 - offset, b] = x++;
                    //left line
                    for (int l = size - 2 - offset; l > offset; l--)
                        taquin[l, offset] = x++;
                    offset++;
                }
                if (size % 2 == 0)
                    taquin[size / 2, size / 2 - 1] = 0;
            }
            else
            {
                for(int i = 0; i < size; i++)
                    for(int j = 0; j < size; j++)
                        taquin[i, j] = x++;
                taquin[size -1, size - 1] = 0;
            }

            return (taquin);
        }

        public static int[,] Shuffle(int[,] taquin, int size)
        {
            Random random = new Random();

            for (int i = size - 1; i > 0; i--) 
            {
                for (int j = size - 1; j > 0; j--) 
                {
                    int m = random.Next(i + 1);
                    int n = random.Next(j + 1);
                    int temp = taquin[i, j];
                    taquin[i, j] = taquin[m, n];
                    taquin[m, n] = temp;
                }
            }
            return (taquin);
        }

        public static int[,] Puzzle(int size, bool shuffle = true, bool unsolvable = false, bool inline = false)
        {
            var taquin = new int[size, size];
            int limitSize = 20;

            if (size <= limitSize && size >= 3) //fixer une valeur plus tard
            {
                taquin = GenerateTaquin(size, inline);

                if (unsolvable)
                {
                    while (true)
                    {
                        if (!Checker.CheckTaquin(Shuffle(taquin, size), size, inline))
                            break;
                    }
                }
                else if (shuffle) //si on veux une liste dans un ordre random
                {
                    while (true)
                    {
                        if (Checker.CheckTaquin(Shuffle(taquin, size), size, inline))
                            break;
                    }
                }
            }
            else
                throw new ExceptionThisIsTooMuch("It's too much or maybe not enough.... You asked for " + size + ". Limits are 3 to " + limitSize);

            return (taquin);
        }
    }
}