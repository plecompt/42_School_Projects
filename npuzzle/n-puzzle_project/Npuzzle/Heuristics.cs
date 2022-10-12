using System;

namespace Npuzzle
{
    public static class Heuristics
    {
        private static double Manhattan<T>(T[,] child, T[,] model, int size)
        {
            double sum = 0;

            for (int i = 0; i < size; i++)
                for(int j = 0; j < size; j++)
                    if (!child[i, j].Equals(0))
                    {
                        var destination = Checker.CoordinatesOf(model, child[i, j]);
                        var distance = Math.Abs(destination.Item1 - i) + Math.Abs(destination.Item2 - j);
                        sum += distance;
                    }
            return sum;
        }

        private static double Euclidien<T>(T[,] child, T[,] model, int size)
        {
            double sum = 0;

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (!child[i, j].Equals(0))
                    {
                        var destination = Checker.CoordinatesOf(model, child[i, j]);
                        var distance = Math.Sqrt(Math.Pow(destination.Item1 - i, 2) + Math.Pow(destination.Item2 - j, 2));
                        sum += distance;
                    }
            return sum;
        }

        private static double Diagonals<T>(T[,] child, T[,] model, int size)
        {
            double sum = 0;

            for (int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    if (!child[i, j].Equals(0))
                    {
                        var destination = Checker.CoordinatesOf(model, child[i, j]);
                        var distance = Math.Abs(destination.Item1 - i) + Math.Abs(destination.Item2 - j);
                        //Console.WriteLine("y:{0}, x:{1}. Destination(y):{2}, Destination(x):{3}", i, j, destination.Item1, destination.Item2);
                        sum += distance;
                        
                        var positionPion = i * size + j;
                        var positionDestination = destination.Item1 * size + destination.Item2;
                        
                        //Console.WriteLine("i:{0}, j:{1}", i, j);
                        if (destination.Item1 == 0 && destination.Item2 == 0) //angle top gauche donc seulement c + t + 1
                        {
                            if (positionDestination + size + 1 == positionPion)
                                if (Checker.CoordinatesOf(child, child[i, j - 1]).Equals(Checker.CoordinatesOf(model, child[i, j - 1])) && Checker.CoordinatesOf(child, child[i - 1, j]).Equals(Checker.CoordinatesOf(model, child[i - 1, j])))
                                    sum += 2;
                        }
                        else if (destination.Item1 == 0 && destination.Item2 == size - 1) //angle top droit donc seulement c + t - 1
                        {
                            if (positionDestination + size - 1 == positionPion)
                                if (Checker.CoordinatesOf(child, child[i, j + 1]).Equals(Checker.CoordinatesOf(model, child[i, j + 1])) && Checker.CoordinatesOf(child, child[i - 1, j]).Equals(Checker.CoordinatesOf(model, child[i - 1, j])))
                                    sum += 2;
                        }
                        else if (destination.Item1 == size - 1 && destination.Item2 == 0) //angle bas gauche donc seulement c - t + 1
                        {
                            if (positionDestination - size + 1 == positionPion)
                                if (Checker.CoordinatesOf(child, child[i, j - 1]).Equals(Checker.CoordinatesOf(model, child[i, j - 1])) && Checker.CoordinatesOf(child, child[i + 1, j]).Equals(Checker.CoordinatesOf(model, child[i + 1, j])))
                                    sum += 2;
                        }
                        else if (destination.Item1 == size - 1 && destination.Item2 == size - 1) //angle bad droit donc seulement c - t - 1
                        {
                            if (positionDestination - size - 1 == positionPion)
                                if (Checker.CoordinatesOf(child, child[i, j + 1]).Equals(Checker.CoordinatesOf(model, child[i, j + 1])) && Checker.CoordinatesOf(child, child[i + 1, j]).Equals(Checker.CoordinatesOf(model, child[i + 1, j])))
                                    sum += 2;
                        }
                        else if (destination.Item2 == 0) //cot� gauche donc seulement c + t + 1 && c - t + 1
                        {
                            if (positionDestination + size + 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i - 1, j]).Equals(Checker.CoordinatesOf(model, child[i - 1, j])) && Checker.CoordinatesOf(child, child[i, j - 1]).Equals(Checker.CoordinatesOf(model, child[i, j - 1])))
                                    sum += 2;
                            }
                            else if (positionDestination - size + 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i, j - 1]).Equals(Checker.CoordinatesOf(model, child[i, j - 1])) && Checker.CoordinatesOf(child, child[i + 1, j]).Equals(Checker.CoordinatesOf(model, child[i + 1, j])))
                                    sum += 2;
                            }
                        }
                        else if (destination.Item2 == size - 1) //coté droit donc seulement c + t - 1 et c - t - 1
                        {
                            if (positionDestination - size - 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i + 1, j]).Equals(Checker.CoordinatesOf(model, child[i + 1, j])) && Checker.CoordinatesOf(child, child[i, j + 1]).Equals(Checker.CoordinatesOf(model, child[i, j + 1])))
                                    sum += 2;
                            }
                            else if (positionDestination + size - 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i - 1, j]).Equals(Checker.CoordinatesOf(model, child[i - 1, j])) && Checker.CoordinatesOf(child, child[i, j + 1]).Equals(Checker.CoordinatesOf(model, child[i, j + 1])))
                                    sum += 2;
                            }
                        }
                        else if (destination.Item1 == 0) // top donc seulement c + t + 1 et c + t - 1
                        {
                            if (positionDestination + size + 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i - 1, j]).Equals(Checker.CoordinatesOf(model, child[i - 1, j])) && Checker.CoordinatesOf(child, child[i, j - 1]).Equals(Checker.CoordinatesOf(model, child[i, j - 1])))
                                    sum += 2;
                            }
                            else if (positionDestination + size - 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i - 1, j]).Equals(Checker.CoordinatesOf(model, child[i - 1, j])) && Checker.CoordinatesOf(child, child[i, j + 1]).Equals(Checker.CoordinatesOf(model, child[i, j + 1])))
                                    sum += 2;
                            }
                        }
                        else if (destination.Item1 == size - 1) // bot donc seulement c - t - 1 et c - t + 1
                        {
                            if (positionDestination - size - 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i + 1, j]).Equals(Checker.CoordinatesOf(model, child[i + 1, j])) && Checker.CoordinatesOf(child, child[i, j + 1]).Equals(Checker.CoordinatesOf(model, child[i, j + 1])))
                                    sum += 2;
                            }
                            else if (positionDestination - size + 1 == positionPion)
                            {
                                if (Checker.CoordinatesOf(child, child[i + 1, j]).Equals(Checker.CoordinatesOf(model, child[i + 1, j])) && Checker.CoordinatesOf(child, child[i, j - 1]).Equals(Checker.CoordinatesOf(model, child[i, j - 1])))
                                    sum += 2;
                            }
                        }
                    }
                }
            }
            return sum;
        }

        private static double TilesOutOfRowAndColumn<T>(T[,] child, T[,] model, int size)
        {
            double sum = 0;

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (!child[i, j].Equals(0))
                    {
                        var destination = Checker.CoordinatesOf(model, child[i, j]);
                        var distance = (destination.Item1 != i ? 1 : 0) + (destination.Item2 != j ? 1 : 0);
                        sum += distance;
                    }
            return sum;
        }

        private static double MisplacedTiles<T>(T[,] child, T[,] model, int size)
        {
            double sum = 0;

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    if (!child[i, j].Equals(0))
                    {
                        var destination = Checker.CoordinatesOf(model, child[i, j]);
                        if (destination.Item1 != i || destination.Item2 != j)
                            sum += 1;
                    }
            return sum;
        }

        public static double Value<T>(int type, T[,] child, T[,] model, int size)
        {
            double heuristicValue = 0;

            switch (type)
            {
                case 1:
                    heuristicValue = Manhattan(child, model, size);
                    break;

                case 2:
                    heuristicValue = Euclidien(child, model, size);
                    break;

                case 3:
                    heuristicValue = Diagonals(child, model, size);
                    break;

                case 4:
                    heuristicValue = TilesOutOfRowAndColumn(child, model, size);
                    break;

                case 5:
                    heuristicValue = MisplacedTiles(child, model, size);
                    break;
            }
            return (heuristicValue);
        }
    }
}