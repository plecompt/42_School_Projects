using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;

namespace Npuzzle
{
    public static class Parser
    {
        private static List<List<string>> ToTableStringTable(List<string> file, int size)
        {
            List<List<string>> datas = new List<List<string>>();
            
            foreach (var line in file)
                datas.Add(line.Split(' ').ToList());
            return datas;
        }

        private static List<int> ToIntTable(List<List<int>> datas, int size)
        {
            List<int> ret = new List<int>();
            
            foreach (var line in datas)
                foreach(var number in line)
                ret.Add(number);
            return ret;
        }

        private static List<int> ToIntTable(int[,] datas, int size)
        {
            List<int> ret = new List<int>();
            
            for(int i = 0; i < size; i++)
                for(int j = 0; j < size; j++)
                    ret.Add(datas[i, j]);
            return ret;
        }

        private static List<List<int>> ToTableIntTable(List<List<string>> datas, int size)
        {
            List<List<int>> table = new List<List<int>>();
            
            foreach (var line in datas.Skip(1))
            {
                List<int> tmp = new List<int>();
                foreach (var str in line)
                {
                    var number = 0;
                    if (!Int32.TryParse(str, NumberStyles.Number, CultureInfo.InvariantCulture, out number))
                        throw new ExceptionInvalidData("Invalid data.");
                    tmp.Add(number);
                }
                table.Add(tmp);
            }
            return table;
        }

        private static int[,] ToFinalTable(List<List<int>> datas, int size)
        {
            var ret = new int[size, size];

            for (int i = 0; i < datas.Count; i++)
                for (int j = 0; j < datas[i].Count; j++)
                    ret[i, j] = datas[i][j];
            return ret;
        }
        private static int GetTheSize(List<string> file)
        {
            int size = -1;

            if (file.Count >= 1)
                if (!Int32.TryParse(file[0], NumberStyles.Number, CultureInfo.InvariantCulture, out size))
                    throw new ExceptionInvalidSize("Invalid Size");
            return size; 
        }

        private static void Display(List<int> datas, int size)
        {
            foreach(var nb in datas)
                Console.WriteLine(nb);
            Console.WriteLine();
        }

        private static void CheckEveryNumber(List<List<int>> datas, int[,] model, int size)
        {
            var structuredDatas = ToIntTable(datas, size);
            var structuredModel = ToIntTable(model, size);

            structuredDatas.Sort();
            structuredModel.Sort();

            for(int i = 0; i < size * size; i++)
                if (structuredDatas[i] != structuredModel[i])
                    throw new ExceptionInvalidData("Invalid datas");        
        }

        private static void CheckNumberOfNumber(List<List<int>> datas, int size)
        {
            int nb_elems = 0;
            
            foreach (var line in datas)
                foreach (var number in line)
                {
                    if (number < 0)
                        throw new ExceptionInvalidData("Invalid number.");
                    nb_elems++;
                }
            
            if ((size * size != nb_elems) || size < 3 || size > 20) //20 is a magic number.
                throw new ExceptionInvalidSize("Invalid Npuzzle size/number of data.");
        }

        public static (int[,] datas, int size) ParseThatFile(List<string> file)
        {
            List<List<string>> datasString = new List<List<string>>();
            List<List<int>> datasInt = new List<List<int>>();
            int size = GetTheSize(file);
            var model = Generate.Puzzle(size, false, false, false); //generate goalTaquin
            
            datasString = ToTableStringTable(file, size);
            datasInt = ToTableIntTable(datasString, size);
            CheckNumberOfNumber(datasInt, size);
            CheckEveryNumber(datasInt, model, size);

            return (ToFinalTable(datasInt, size), size);
        }
    }
}