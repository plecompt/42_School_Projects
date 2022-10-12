using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text.RegularExpressions;

namespace ComputorV1
{
    class Program
    {
        static void Main(string[] args)
        {
            string expression = "";

            switch (args.Length)
            {
                case 0:
                    Console.WriteLine("Please enter an equation:");
                    expression = Console.ReadLine();
                    break;
                case 1:
                    expression = args[0];
                    break;
                default:
                    Console.WriteLine("Equation must be the only argument and must be inclosed in quotes.");
                    break;
            }
            try
            {
                (List<(double, int)> LeftTerms, List<(double, int)> RightTerms) = Parse(expression);
                Reduce(LeftTerms, RightTerms);
                CheckPolynomialLevel(LeftTerms, RightTerms);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

        }

        static void CheckPolynomialLevel(List<(double, int)> LeftTerms, List<(double, int)> RightTerms)
        {
            int degre = ReturnHighestDegree(LeftTerms);
            double pow2 = TermPower(LeftTerms, 2);
            double pow1 = TermPower(LeftTerms, 1);
            double pow0 = TermPower(LeftTerms, 0);

            Console.WriteLine("\nPolynomial degree: {0}", degre);

            foreach (var item in LeftTerms)
                if (item.Item2 > 2 || item.Item2 < 0 && (item.Item2 != 1 && item.Item2 != 2 && item.Item2 != 0))
                    throw new Exception($"The polynomial degree must be between 0 and 2 and term's degree can't be lower than 0 or higher than 2. Invalid term: {item.Item1}X^{item.Item2}.");

            if (LeftTerms.Count() == 0 && RightTerms.Count == 0)
                throw new Exception("All real numbers are solution.");
            if (LeftTerms.Count() == 1 && LeftTerms[0].Item2 == 0 && RightTerms.Count() == 0)
                throw new Exception("No Solution.");
            if (degre == 1)
                Solve1stDegree(pow1, -pow0);
            if (degre == 2)
                Solve2ndDegree(pow2, pow1, pow0);
        }

        static IEnumerable<string> SplitAndKeep(string s, char[] delims)
        {
            int i = 1;
            int index = 0;

            while (i < s.Length)
            {
                while (i < s.Length && !delims.Contains(s[i]))
                    i++;
                if (i > index && s[i - 1] != '^')
                {
                    yield return s.Substring(index, i - index);
                    index = i;
                }
                i++;
            }
        }

        static (List<(double, int)>, List<(double, int)>) Parse(string expression)
        {
            IEnumerable<string> left;
            IEnumerable<string> right;
            string str;
            var LeftTerms = new List<(double, int)>();
            var RightTerms = new List<(double, int)>(); ;

            str = expression.Replace(",", "."); //remplace les ',' par des '.'
            str = Regex.Replace(str, @"[*xX ]", ""); //remplace les 'x', 'X', et ' ' par ''.

            left = SplitAndKeep(str.Split('=').First(), new char[] { '+', '-' }); //recupere tous les termes de gauche
            right = SplitAndKeep(str.Split('=').Last(), new char[] { '+', '-' }); //recupere tous les termes de droite

            foreach (var elem in left)
                LeftTerms.Add((double.Parse(elem.Split('^').First(), CultureInfo.InvariantCulture), Int32.Parse(elem.Split('^').Last(), CultureInfo.InvariantCulture)));

            foreach (var elem in right)
                RightTerms.Add((double.Parse(elem.Split('^').First(), CultureInfo.InvariantCulture), Int32.Parse(elem.Split('^').Last(), CultureInfo.InvariantCulture)));

            return (LeftTerms, RightTerms);
        }

        static void WriteNaturalForm(List<(double, int)> LeftTerms, List<(double, int)> RightTerms, bool reduced)
        {
            bool first = true;
            bool first2 = true;

            foreach (var item in LeftTerms)
            {
                if (!first)
                    Console.Write(" ");
                Console.ForegroundColor = ConsoleColor.Red;
                if (item.Item1.ToString()[0] == '-')
                {
                    Console.Write(item.Item1);
                    if (item.Item2 != 0)
                        Console.Write("x");
                }
                else
                {
                    Console.Write("+" + item.Item1);
                    if (item.Item2 != 0)
                        Console.Write("x");
                }
                if (item.Item2 != 0)
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("^" + item.Item2);
                }
                Console.ForegroundColor = ConsoleColor.White;
                first = false;

            }

            if (LeftTerms.Count() == 0 && reduced)
                Console.Write("0");
            if (!reduced)
                Console.Write(" = ");
            else
                Console.Write(" = 0");

            foreach (var item in RightTerms)
            {
                if (!first2)
                    Console.Write(" ");
                Console.ForegroundColor = ConsoleColor.Red;
                if (item.Item1.ToString()[0] == '-')
                {
                    Console.Write(item.Item1);
                    if (item.Item2 != 0)
                        Console.Write("x");
                }
                else
                {
                    Console.Write("+" + item.Item1);
                    if (item.Item2 != 0)
                        Console.Write("x");
                }
                if (item.Item2 != 0)
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                    Console.Write("^" + item.Item2);
                }
                Console.ForegroundColor = ConsoleColor.White;
                first2 = false;
            }
        }

        static void Reduce(List<(double, int)> LeftTerms, List<(double, int)> RightTerms)
        {
            //Checking if missing terms
            if (LeftTerms.Count() == 0 || RightTerms.Count() == 0)
                throw new Exception("Invalid Equation. Missing term(s).");

            Console.Write("Natural Form: ");
            WriteNaturalForm(LeftTerms, RightTerms, false);

            //Right to Left
            var inv = (.0, 0);
            for (int i = RightTerms.Count - 1; i >= 0; i--)
            {
                inv = RightTerms[i];
                inv.Item1 *= -1;
                LeftTerms.Add(inv);
                RightTerms.RemoveAt(i);
            }
            Console.WriteLine();
            WriteNaturalForm(LeftTerms, RightTerms, true);

            //Calculations
            var max = ReturnHighestDegree(LeftTerms);
            for (int i = 0; i <= max; i++)
            {
                inv = (0, i);
                foreach (var grp in LeftTerms.ToList())
                {
                    if (grp.Item2 == i)
                    {
                        inv.Item1 += grp.Item1;
                        LeftTerms.Remove(grp);
                    }
                }
                if (inv.Item1 != 0)
                {
                    LeftTerms.Add(inv);
                    Console.WriteLine();
                    WriteNaturalForm(LeftTerms, RightTerms, true);
                }
            }

            Console.Write("\nReduced Form: ");
            WriteNaturalForm(LeftTerms, RightTerms, true);

            // if (LeftTerms.Count() == 0 && RightTerms.Count == 0)
            //     throw new Exception("\nAll real numbers are solution.");
            // if (LeftTerms.Count() == 1 && LeftTerms[0].Item2 == 0 && RightTerms.Count() == 0)
            //     throw new Exception("\nNo Solution.");
        }

        static void Solve1stDegree(double a, double b)
        {
            if (a == (int)a && b == (int)b)
            {
                Console.WriteLine("{0}x = {1}", a, b);
                if (b % a == 0)
                    Console.WriteLine("x = {0}", b / a);
                else if (b < 0 && a < 0)
                    Console.WriteLine("x = {0}/{1}", -b, -a);
                else
                    Console.WriteLine("x = {0}/{1}", b, a);
            }
            else
            {
                Console.WriteLine("{0}x = {1}", a, b);
                if (b < 0 && a < 0)
                    Console.WriteLine("x = {0}", -b/ -a);
                else
                    Console.WriteLine("x = {0}", b / a);
            }
        }

        static void Solve2ndDegree(double a, double b, double c)
        {
            double delta = b * b - 4 * a * c;
            double real;
            double imaginary;
            double x1;
            double x2;

            Console.WriteLine("Delta = b² -4ac = {0}", delta);

            if (delta > 0)
            {
                Console.WriteLine("Discriminant is strictly positive, the two solutions are:");
                x1 = (-b + MySqrt(delta)) / (2 * a);
                x2 = (-b - MySqrt(delta)) / (2 * a);
                Console.WriteLine("x1 = (-b + sqrt(delta)) / 2a\nx1 = ({0} + sqrt({1})) / 2 * {2}\nx1 = {3}", -b, delta, a, x1);
                Console.WriteLine("x2 = (-b - sqrt(delta)) / 2a\nx2 = ({0} + sqrt({1})) / 2 * {2}\nx2 = {3}", -b, delta, a, x2);
            }
            else if (delta == 0)
            {
                Console.WriteLine("Discriminant is equal 0, the solution is:");
                x1 = (-b + MySqrt(delta)) / (2 * a);
                Console.WriteLine("x = (-b + sqrt(delta)) / 2a\n({0} + sqrt({1})) / 2 * {2}\nx1 = {3}", -b, delta, a, x1);
            }
            else
            {
                delta = -delta;
                real = (b != 0 ? -b / (2 * a) : real = b / (2 * a));
                imaginary = MySqrt(delta) / (2 * a);
                Console.WriteLine("Discriminant is less than 0, the two imaginary solutions are:");
                Console.WriteLine("Delta = -Delta\nReal Part = -b / 2a\nImaginary Part = sqrt(delta) / 2a");
                Console.WriteLine("Delta = {0}\nReal Part = {1}\nImaginary Part = {2}", delta, real, imaginary);
                Console.WriteLine("x1 = {0,4:f4} + {1,4:f4}i", real, imaginary);
                Console.WriteLine("x2 = {0,4:f4} - {1,4:f4}i", real, imaginary);
            }
        }

        static int ReturnHighestDegree(List<(double, int)> LeftTerms)
        {
            if (LeftTerms.Count == 0)
                return 0;

            int max = Int32.MinValue;

            foreach (var item in LeftTerms)
                if (item.Item2 > max)
                    max = item.Item2;

            return (max);
        }

        static double MySqrt(double x)
        {
            double d = 0.0000001;

            if (x <= 0)
                return (x);

            while (d * d < x)
                d += 0.0000001;

            return (double.Parse(d.ToString("0.####")));
        }

        static double TermPower(List<(double, int)> LeftTerms, int power)
        {
            double coef = 0;

            foreach (var term in LeftTerms)
                if (term.Item2 == power)
                    coef = term.Item1;
            return coef;
        }
    }
}
