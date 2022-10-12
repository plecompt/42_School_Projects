using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace Npuzzle
{
    class AStar3<T> where T : IComparable
    {
        private readonly StateNode<T> _goal;
        private T Empty { get; set; }
        private PriorityQueue<StateNode<T>> _openList;
        private HashSet<string> _closedList;
        private List<StateNode<T>> _path;

        private int _heuristic;

        private StateNode<T> _current;

        private Action[] _functions;
        private int _index;
        private StateNode<T> _myvalue;
        private bool _debug;

        public int GetComplexityInSize
        {
            get { return (_openList.Count + _closedList.Count); }
        }
        public int GetComplexityInTime
        {
            get { return (_closedList.Count); }
        }
        public int GetOpenList
        {
            get { return (_openList.Count); }
        }
        public int GetIndex
        {
            get { return (_index); }
        }
        public List<StateNode<T>> getSolution(StateNode<T> node)
        {
            StateNode<T> temps = node;
            for (int i = node.Depth; i >= 0; i--)
            {
                _path.Add(temps);
                temps = temps.Parent;
            }
            _path.Reverse();
            return (_path);
        }

        public AStar3(StateNode<T> initial, StateNode<T> goal, T empty, int heuristic, int index, bool debug)
        {
            _openList = new PriorityQueue<StateNode<T>>(new[] { initial });
            _functions = new Action[] {ExpandNodes1, ExpandNodes2, ExpandNodes3, ExpandNodes4, ExpandNodes5, ExpandNodes6,
            ExpandNodes7, ExpandNodes8, ExpandNodes9, ExpandNodes10, ExpandNodes11, ExpandNodes12, ExpandNodes13, ExpandNodes14,
            ExpandNodes15, ExpandNodes16, ExpandNodes17, ExpandNodes18, ExpandNodes19, ExpandNodes20, ExpandNodes21, ExpandNodes22,
            ExpandNodes23, ExpandNodes24};
            _goal = goal;
            Empty = empty;
            _closedList = new HashSet<string>();
            _path = new List<StateNode<T>>();
            _heuristic = heuristic;
            _index = index;
            _myvalue = new StateNode<T>();
            _debug = debug;
        }
        public void Clear()
        {
            _openList = null;
            _closedList = null;
            GC.Collect();
        }

        public void Display(int ol, int ct, int cs)
        {
            if (_myvalue == null)
            {
                Console.WriteLine("This configuration is not solvable");
                Console.WriteLine("OpenList : {0}", ol);
                Console.WriteLine("Complexity in time(ClosedList) : {0}", ct);
                Console.WriteLine("Complexity in size(OpenList + ClosedList) : {0}", cs);
            }
            else
            {
                Console.WriteLine("--Solution A*3--\n");
                foreach (var solution in getSolution(_myvalue))
                {
                    switch (solution.Move)
                    {
                        case 'u':
                        Console.WriteLine("Up");
                        break;
                        case 'd':
                        Console.WriteLine("Down");
                        break;
                        case 'l':
                        Console.WriteLine("Left");
                        break;
                        case 'r':
                        Console.WriteLine("Right");
                        break;
                    }
                    if (_debug)
                        solution.Print();
                }
                Console.WriteLine("--End Of Solution--\n");

                Console.WriteLine("Node at depth (Number of move): {0}", _myvalue.Depth);
                Console.WriteLine("OpenList: {0}", ol);
                Console.WriteLine("Complexity in time (ClosedList): {0}", ct);
                Console.WriteLine("Complexity in size (OpenList + ClosedList): {0}", cs);
            }
        }

        public void Execute()
        {
            while (_openList.Count > 0)
            {
                _current = _openList.Pop();
                _closedList.Add(_current.StrRepresentation);
                if (_current.StrRepresentation.Equals(_goal.StrRepresentation))
                {
                    _myvalue = _current;
                    return;
                }
                _functions[_index]();
            }
            _myvalue = null;
            return;
        }

        public (T, T[,]) SwapTile(int nrow, int ncol, StateNode<T> node)
        {
            T temp;
            T[,] newState;

            newState = node.State.Clone() as T[,];
            temp = newState[node.EmptyRow + nrow, node.EmptyCol + ncol];
            newState[node.EmptyRow + nrow, node.EmptyCol + ncol] = Empty;
            newState[node.EmptyRow, node.EmptyCol] = temp;

            return (temp, newState);
        }

        private void ExpandNodes1()
        {
            Up();
            Down();
            Left();
            Right();
        }

        private void ExpandNodes2()
        {
            Up();
            Down();
            Right();
            Left();
        }

        private void ExpandNodes3()
        {
            Up();
            Right();
            Down();
            Left();
        }

        private void ExpandNodes4()
        {
            Up();
            Right();
            Left();
            Down();
        }

        private void ExpandNodes5()
        {
            Up();
            Left();
            Down();
            Right();
        }

        private void ExpandNodes6()
        {
            Up();
            Left();
            Right();
            Down();
        }

        private void ExpandNodes7()
        {
            Down();
            Up();
            Left();
            Right();
        }

        private void ExpandNodes8()
        {
            Down();
            Up();
            Right();
            Left();
        }
        private void ExpandNodes9()
        {
            Down();
            Left();
            Up();
            Right();
        }

        private void ExpandNodes10()
        {
            Down();
            Left();
            Right();
            Up();
        }

        private void ExpandNodes11()
        {
            Down();
            Right();
            Up();
            Left();
        }

        private void ExpandNodes12()
        {
            Down();
            Right();
            Left();
            Up();
        }

        private void ExpandNodes13()
        {
            Left();
            Up();
            Down();
            Right();
        }

        private void ExpandNodes14()
        {
            Left();
            Up();
            Right();
            Down();
        }

        private void ExpandNodes15()
        {
            Left();
            Down();
            Up();
            Right();
        }

        private void ExpandNodes16()
        {
            Left();
            Down();
            Right();
            Up();
        }

        private void ExpandNodes17()
        {
            Left();
            Right();
            Up();
            Down();
        }

        private void ExpandNodes18()
        {
            Left();
            Right();
            Down();
            Up();
        }

        private void ExpandNodes19()
        {
            Right();
            Up();
            Down();
            Left();
        }

        private void ExpandNodes20()
        {
            Right();
            Up();
            Left();
            Down();
        }

        private void ExpandNodes21()
        {
            Right();
            Down();
            Up();
            Left();
        }

        private void ExpandNodes22()
        {
            Right();
            Down();
            Left();
            Up();
        }

        private void ExpandNodes23()
        {
            Right();
            Left();
            Up();
            Down();
        }

        private void ExpandNodes24()
        {
            Right();
            Left();
            Down();
            Up();
        }
        private void Up()
        {
            var col = _current.EmptyCol;
            var row = _current.EmptyRow;
            StateNode<T> newNode;


            // Up
            if (row > 0)
            {
                (T temp, T[,] newState) = SwapTile(-1, 0, _current);
                newNode = new StateNode<T>(newState, row - 1, col, _current.Depth + 1);
                newNode.Parent = _current;

                if (!_closedList.Contains(newNode.StrRepresentation))
                {
                    newNode.Value = newNode.Depth + Heuristics.Value(_heuristic, newNode.State, _goal.State, _goal.Size);
                    newNode.Move = 'u';
                    _openList.Add(newNode);
                }
            }
        }

        private void Down()
        {
            var col = _current.EmptyCol;
            var row = _current.EmptyRow;
            StateNode<T> newNode;


            // Down
            if (row < _current.Size - 1)
            {
                (T temp, T[,] newState) = SwapTile(+1, 0, _current);
                newNode = new StateNode<T>(newState, row + 1, col, _current.Depth + 1);
                newNode.Parent = _current;

                if (!_closedList.Contains(newNode.StrRepresentation))
                {
                    newNode.Value = newNode.Depth + Heuristics.Value(_heuristic, newNode.State, _goal.State, _goal.Size);
                    newNode.Move = 'd';
                    _openList.Add(newNode);
                }
            }
        }

        private void Left()
        {
            var col = _current.EmptyCol;
            var row = _current.EmptyRow;
            StateNode<T> newNode;


            // Left
            if (col > 0)
            {
                (T temp, T[,] newState) = SwapTile(0, -1, _current);
                newNode = new StateNode<T>(newState, row, col - 1, _current.Depth + 1);
                newNode.Parent = _current;

                if (!_closedList.Contains(newNode.StrRepresentation))
                {
                    newNode.Value = newNode.Depth + Heuristics.Value(_heuristic, newNode.State, _goal.State, _goal.Size);
                    newNode.Move = 'l';
                    _openList.Add(newNode);
                }
            }
        }

        private void Right()
        {
            var col = _current.EmptyCol;
            var row = _current.EmptyRow;
            StateNode<T> newNode;


            // Right
            if (col < _current.Size - 1)
            {
                (T temp, T[,] newState) = SwapTile(0, +1, _current);
                newNode = new StateNode<T>(newState, row, col + 1, _current.Depth + 1);
                newNode.Parent = _current;

                if (!_closedList.Contains(newNode.StrRepresentation))
                {
                    newNode.Value = newNode.Depth + Heuristics.Value(_heuristic, newNode.State, _goal.State, _goal.Size);
                    newNode.Move = 'r';
                    _openList.Add(newNode);
                }
            }
        }
    }
}