using System;
using System.Collections.Generic;
using System.Text.RegularExpressions;

namespace Npuzzle
{
    public static class Lexer
    {
        private static void Debug(List<string> file, string message = "", bool showEndOfLine = true)
        {
            Console.WriteLine(message);
            foreach (var line in file)
                Console.WriteLine(line + (showEndOfLine ? '|' : '\0'));
            Console.WriteLine("----");
        }

        private static string RemoveExtraWhiteSpaces(string line)
        {
            Regex trimmer = new Regex(@"\s\s+"); //remove extra whitespaces

            line = trimmer.Replace(line, " ");
            line = line.TrimStart();
            line = line.TrimEnd();
            return (line);
        }

        private static string RemoveComments(string line)
        {
            if (line.Contains('#'))
                line = line.Substring(0, line.IndexOf('#'));

            return line;
        }

        private static void RemoveEmptyLine(List<string> file)
        {
            for (int i = file.Count - 1; i > -1; i--)
                if (file[i] == string.Empty) file.RemoveAt(i);
        }

        public static List<string> CheckThatFile(List<string> file)
        {
            //debug
            //Debug(file, "Before");

            for (int i = 0; i < file.Count; i++)
            {
                //remove comments.
                file[i] = RemoveComments(file[i]);

                //remove extrawhitespaces.
                file[i] = RemoveExtraWhiteSpaces(file[i]);
            }

            RemoveEmptyLine(file);

            //debug
            //Debug(file, "After");

            return file;
        }
    }
}