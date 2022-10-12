using System.Collections.Generic;

namespace ExpertSystem
{
    public static class Logic
    {
        public static bool Single(bool a, bool notA)
        {
            return notA ? (!a) : (a);
        }
        public static bool Or(bool a, bool b) // a ou b ou a et b
        {
            return (a && b) || (a && !b) || (b && !a) ? (true) : (false);
        }

        public static bool Xor(bool a, bool b) // a ou b
        {
            return (a && !b) || (b && !a) ? true : false;
        }

        public static bool And(bool a, bool b) // a et b
        {
            return a && b ? true : false;
        }

        public static IList<Data> Implies(bool a, IList<Data> newFacts, List<char> previousFacts)
        {
            foreach (var elem in previousFacts)
                foreach (var fact in newFacts)
                    if (elem == fact.nom && fact.value == false)
                        throw new ContradictionError("Error: contradiction.");

            if (a)
                for (int i = 0; i < newFacts.Count; i++)
                    if (!previousFacts.Contains(newFacts[i].nom))
                        newFacts[i].value = !newFacts[i].value;

            return (newFacts);
        }
    }
}
