using System;

namespace Npuzzle
{
    class StateNode<T> : IComparable<StateNode<T>> where T : IComparable
    {
        public StateNode<T> Parent;
        public double Value { get; set; }
        public char Move { get; set; }
        public T[,] State { get; private set; }
        public int EmptyCol { get; private set; }
        public int EmptyRow { get; private set; }
        public int Depth { get; set; }
        public string StrRepresentation { get; set; }

        public StateNode() { }

        public StateNode(T[,] state, int emptyRow, int emptyCol, int depth)
        {
            if (state.GetLength(0) != state.GetLength(1))
                throw new Exception("Number of columns and rows must be the same");

            State = state.Clone() as T[,];
            EmptyRow = emptyRow;
            EmptyCol = emptyCol;
            Depth = depth;

            for (var i = 0; i < State.GetLength(0); i++)
            {
                for (var j = 0; j < State.GetLength(1); j++)
                    StrRepresentation += State[i, j] + ",";
            }
        }

        public StateNode(T[,] state, Tuple<int, int> indexof0, int depth)
        {
            if (state.GetLength(0) != state.GetLength(1))
                throw new Exception("Number of columns and rows must be the same");

            State = state.Clone() as T[,];
            EmptyRow = indexof0.Item1;
            EmptyCol = indexof0.Item2;
            Depth = depth;

            for (var i = 0; i < State.GetLength(0); i++)
            {
                for (var j = 0; j < State.GetLength(1); j++)
                    StrRepresentation += State[i, j] + ",";
            }
        }

        public int Size
        {
            get { return State.GetLength(0); }
        }

        public void Print()
        {
            for (var i = 0; i < State.GetLength(0); i++)
            {
                for (var j = 0; j < State.GetLength(1); j++)
                {
                    if (State[i, j].Equals(0))
                    {
                        Console.ForegroundColor = ConsoleColor.Red;
                        Console.Write(String.Format("{0:000}", State[i, j]) + ((j != State.GetLength(1) - 1) ? " " : ""));
                        Console.ResetColor();
                    }
                    else
                        Console.Write(String.Format("{0:000}", State[i, j]) + ((j != State.GetLength(1) - 1) ? " " : ""));
                }
                Console.WriteLine();
            }
            Console.WriteLine();
        }

        public int CompareTo(StateNode<T> other)
        {
            if (Value > other.Value)
                return 1;
            if (Value < other.Value)
                return -1;

            return 0;
        }
    }
}