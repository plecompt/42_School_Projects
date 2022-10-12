using System.Collections.Generic;
using System.Linq;

namespace ExpertSystem
{
    public static class Facts
    {
        public static List<char[]> ExtractFactsAndQuerries(List<char> datas, string trim)
        {
            List<char[]> formatedOutput = new List<char[]>();

            var elems = string.Concat(datas).Split(trim);
            foreach (var substring in elems.Skip(1))
                formatedOutput.Add(substring.ToCharArray());

            return formatedOutput;
        }

    }
}
