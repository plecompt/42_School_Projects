using System;

namespace ExpertSystem
{
    public class ExceptionSyntaxError : Exception
    {
        public ExceptionSyntaxError(string message) : base(message) { }
    }

    public class ContradictionError : Exception
    {
        public ContradictionError(string message) : base(message) { }
    }

    public class BonusError : Exception
    {
        public BonusError(string message) : base(message) { }
    }
}
