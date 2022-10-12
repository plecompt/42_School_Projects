using System;
using System.Collections.Generic;
using System.Text;

namespace TestProject
{
    public static class Analyzer
    {
        public static bool Analyse(List<Tuple<string, string, List<string>>> trueDatas, List<Tuple<string, string, List<string>>> testDatas)
        {
            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == testDatas[i].Item1))
                    return false;
                if (!(trueDatas[i].Item2 == testDatas[i].Item2))
                    return false;
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[i].Item3[j] == testDatas[i].Item3[j]))
                        return false;
            }
            return true;
        }
    }
}
