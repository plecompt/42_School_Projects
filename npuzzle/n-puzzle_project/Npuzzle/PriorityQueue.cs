using System;
using System.Collections;
using System.Collections.Generic;

namespace Npuzzle
{
    public class PriorityQueue<T> : ICollection<T>, ICloneable
    {
        public const int DefaultSize = 10;

        private T[] _Tree;
        private int _NumberOfItems;
        private IComparer<T> _Comparer;

        public object Clone()
        {
            return this.MemberwiseClone();
        }
        public PriorityQueue()
        {

        }
        public PriorityQueue(T[] item) : this(Comparer<T>.Default, item)
        {
            
        }
        public PriorityQueue(IComparer<T> comparer, T[] item)
        {
            _Tree = new T[Math.Max(DefaultSize, item.Length)];
            item.CopyTo(_Tree, 0);
            _NumberOfItems = item.Length;
            _Comparer = comparer;
        }
        private void SiftDown(int startPos, int pos)
        {
            T newItem = _Tree[pos];
            while (pos > startPos)
            {
                int parentPos = (pos - 1) / 2;
                T parent = _Tree[parentPos];
                if (CompareElements(parent, newItem) <= 0)
                    break;
                _Tree[pos] = parent;
                pos = parentPos;
            }

            _Tree[pos] = newItem;
        }
        private void SiftUp(int pos)
        {
            int endPos = _NumberOfItems;
            int startPos = pos;
            T newItem = _Tree[pos];
            int childPos = (2 * pos) + 1;

            while (childPos < endPos)
            {
                int rightPos = childPos + 1;
                if (rightPos < endPos && CompareElements(_Tree[rightPos], _Tree[childPos]) <= 0)
                    childPos = rightPos;
                _Tree[pos] = _Tree[childPos];
                pos = childPos;
                childPos = (2 * pos) + 1;
            }

            _Tree[pos] = newItem;
            SiftDown(startPos, pos);
        }
        public T Pop()
        {
            if (_NumberOfItems == 0)
                throw new InvalidOperationException("Cannot pop from the heap, it is empty");

            T lastElement = _Tree[--_NumberOfItems];
            _Tree[_NumberOfItems] = default(T);
            T returnItem;
            if (_NumberOfItems > 0)
            {
                returnItem = _Tree[0];
                _Tree[0] = lastElement;
                SiftUp(0);
            }
            else
                returnItem = lastElement;

            return returnItem;
        }

        private int CompareElements(T element1, T element2)
        {
            int result = _Comparer.Compare(element1, element2);
            return result;
        }

        
        public void Add(T item)
        {
            if (_NumberOfItems == _Tree.Length)
                Capacity *= 2;

            _Tree[_NumberOfItems++] = item;
            SiftDown(0, _NumberOfItems - 1);
        }
        void ICollection<T>.Clear()
        {
            throw new NotImplementedException();
        }

        bool ICollection<T>.Contains(T item)
        {
            throw new NotImplementedException();
        }

        void ICollection<T>.CopyTo(T[] array, int arrayIndex)
        {
            throw new NotImplementedException();
        }

        public IEnumerator<T> GetEnumerator()
        {
            for (int index = 0; index < _NumberOfItems; index++)
            {
                yield return _Tree[index];
            }
        }
        IEnumerator IEnumerable.GetEnumerator()
        {
            return GetEnumerator();
        }

        bool ICollection<T>.Remove(T item)
        {
            throw new NotImplementedException();
        }

        bool ICollection<T>.IsReadOnly => throw new NotImplementedException();

        public int Count
        {
            get { return _NumberOfItems; }
        }
        public int Capacity
        {
            get
            {
                return _Tree.Length;
            }

            set
            {
                if (value < _NumberOfItems)
                    throw new ArgumentOutOfRangeException("value", value, "Heap capacity cannot be that small (" + value + "), must at least be equal to Count (" + _NumberOfItems + ")");

                int newSize = Math.Max(value, DefaultSize);
                if (newSize != _Tree.Length)
                {
                    var newElements = new T[newSize];
                    if (_Tree.Length > 0)
                        Array.Copy(_Tree, 0, newElements, 0, Math.Min(_Tree.Length, value));
                    _Tree = newElements;
                }
            }
        }
    }
}
