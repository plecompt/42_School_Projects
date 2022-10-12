using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Threading;

namespace Npuzzle
{
    class AStar2<T> where T : IComparable
    {
        private readonly StateNode<T> _goal;
        private T Empty { get; set; }
        private PriorityQueue<StateNode<T>> _openList;
        private HashSet<string> _closedList;
        private List<StateNode<T>> _path;
        private StateNode<T> _current;
        private int _heuristic;
        private StateNode<T> _myvalue;

        static object _lock;
        private bool _debug;

        public StateNode<T> GetCurrentNode
        {
            get { return (_current); }
        }
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

        public AStar2(StateNode<T> initial, StateNode<T> goal, T empty, int heuristic, bool debug)
        {
            _openList = new PriorityQueue<StateNode<T>>(new[] { initial });

            _goal = goal;
            Empty = empty;
            _closedList = new HashSet<string>();
            _path = new List<StateNode<T>>();
            _heuristic = heuristic;
            _lock = new object();
            _myvalue = new StateNode<T>();
            _debug = debug;
        }
        public void Clear()
        {
            _openList = null;
            _closedList = null;
            GC.Collect();
        }
        public void Display()
        {
            if (_myvalue == null)
            {
                Console.WriteLine("This configuration is not solvable");
                Console.WriteLine("OpenList : {0}", GetOpenList);
                Console.WriteLine("Complexity in time(ClosedList) : {0}", GetComplexityInTime);
                Console.WriteLine("Complexity in size(OpenList + ClosedList) : {0}", GetComplexityInSize);
            }
            else
            {
                Console.WriteLine("--Solution A*2--\n");
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
                Console.WriteLine("OpenList: {0}", GetOpenList);
                Console.WriteLine("Complexity in time (ClosedList): {0}", GetComplexityInTime);
                Console.WriteLine("Complexity in size (OpenList + ClosedList): {0}", GetComplexityInSize);
            }
        }

        public async Task<StateNode<T>> ExecuteAsync()
        {
            while (_openList.Count > 0)
            {
                _current = _openList.Pop();
                _closedList.Add(_current.StrRepresentation);
                if (_current.StrRepresentation.Equals(_goal.StrRepresentation))
                {
                    _myvalue = _current;
                    return _current;
                }
                await ExpandNodesAsync();
            }
            _myvalue = null;
            return null;
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

        private async Task ExpandNodesAsync()
        {
            List<Task> tasks = new List<Task>();
            tasks.Add(Task.Run(() => Up()));
            tasks.Add(Task.Run(() => Down()));
            tasks.Add(Task.Run(() => Left()));
            tasks.Add(Task.Run(() => Right()));

            await Task.WhenAll(tasks);
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
                    lock (_lock)
                    {
                        _openList.Add(newNode);
                    }

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
                    lock (_lock)
                    {
                        _openList.Add(newNode);
                    }
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
                    lock (_lock)
                    {
                        _openList.Add(newNode);
                    }
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
                    lock (_lock)
                    {
                        _openList.Add(newNode);
                    }
                }
            }
        }
    }
}