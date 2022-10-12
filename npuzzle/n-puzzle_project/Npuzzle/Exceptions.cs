using System;
using System.Collections.Generic;
using System.Text;

namespace Npuzzle
{
    public class ExceptionInvalidData : Exception
    {
        public ExceptionInvalidData(string message) : base(message) { }
    }

    public class ExceptionInvalidSize : Exception
    {
        public ExceptionInvalidSize(string message) : base(message) { }
    }

    public class ExceptionThisIsTooMuch : Exception
    {
        public ExceptionThisIsTooMuch(string message) : base(message) { }
    }
}
