using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace ExpertSystem
{
    public static class Lexer
    {
        public static List<Data> CheckThatFile(IList<string> file)
        {
            var lexer = new List<Data>();

            for (int i = 0; i < file.Count; i++)
            {

                if (file[i].Contains('#'))
                    file[i] = file[i].Substring(0, file[i].IndexOf("#"));
                file[i] = Regex.Replace(file[i], @"\s+", "");
                file[i] = Regex.Replace(file[i], @"<=>", "2");
                file[i] = Regex.Replace(file[i], @"=>", "1");
                for (int j = 0; j < file[i].Length; j++)
                {
                    bool type = false;
                    char name = file[i][j];
                    bool value = false;
                    bool eol = false;

                    Regex regex = new Regex(@"[A-Z]");
                    if (regex.Match(file[i][j].ToString()).Success)
                        type = true;
                    if (j == file[i].Length - 1)
                        eol = true;
                    lexer.Add(new Data { nom = name, type = type, value = value, eol = eol });
                }
            }
            return lexer;
        }
    }
}