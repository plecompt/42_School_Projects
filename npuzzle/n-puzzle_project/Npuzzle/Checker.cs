using System;
using System.Collections.Generic;
using System.Linq;

namespace Npuzzle
{
    public static class Checker
    {
        public static bool CheckTaquin(int[,] taquin, int size, bool inline = false)
        {
            var list = new List<int>();
            int sum = 0;
            int offset = 0;

            if (!inline)
            {
                while (offset != size / 2)
                {
                    //top Line
                    for (int f = offset; f < size - offset; f++)
                        list.Add(taquin[offset, f]);
                    //right line
                    for (int r = offset + 1; r < size - offset; r++)
                        list.Add(taquin[r, size - 1 - offset]);
                    //bottom line
                    for (int b = size - 2 - offset; b >= offset; b--)
                        list.Add(taquin[size - 1 - offset, b]);
                    //left line
                    for (int l = size - 2 - offset; l > offset; l--)
                        list.Add(taquin[l, offset]);
                    offset++;
                }
                if (size % 2 == 1)
                    list.Add(taquin[size / 2, size / 2]);
            }
            else
            {
                for(int i = 0; i < size; i++)
                    for(int j = 0; j < size; j++)
                        list.Add(taquin[i, j]);
            }

            for (int i = 0; i < list.Count; i++)
                for(int j = i; j < list.Count; j++)
                    if (list[j] < list[i] && list[i] != 0 && list[j] != 0)
                        sum += 1;

            return (sum % 2 == 0 ? true : false);
        }
        
        public static void CheckArguments(Arguments arguments)
        {
            if (arguments.Algo < 1 || arguments.Algo > 3)
                throw new ExceptionInvalidData("Invalid algorithm argument.");
            if (arguments.Heuristic < 1 || arguments.Heuristic > 5)
                throw new ExceptionInvalidData("Invalid heuristic argument.");
            if (!arguments.Generate  && arguments.Run)
                throw new ExceptionInvalidData("-run require -generate.");
        }
        public static Tuple<int, int> CoordinatesOf<T>(this T[,] matrix, T value)
        {
            int w = matrix.GetLength(0); // width
            int h = matrix.GetLength(1); // height

            for (int x = 0; x < w; ++x)
                for (int y = 0; y < h; ++y)
                    if (matrix[x, y].Equals(value))
                        return Tuple.Create(x, y);

            return Tuple.Create(-1, -1);
        }
    }
}