using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class ComplexOrTestsForSolver
    {
        private string folder = @"testFiles/testSolver/complexTests/testsOr/";

        [TestMethod]
        public void ComplexOrTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));
            trueDatas.Add(Tuple.Create("A", "C", new List<string>() { "C is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "C", new List<string>() { "C is TRUE" }));
            trueDatas.Add(Tuple.Create("", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexOrTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "E", new List<string>() { "E is TRUE" }));
            trueDatas.Add(Tuple.Create("A", "E", new List<string>() { "E is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "E", new List<string>() { "E is TRUE" }));
            trueDatas.Add(Tuple.Create("", "E", new List<string>() { "E is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexOrTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("C", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("D", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("E", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("F", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("G", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("H", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("AB", "Z", new List<string>() { "Z is TRUE" }));
            trueDatas.Add(Tuple.Create("DE", "Z", new List<string>() { "Z is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexOrTest04()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "B", new List<string>() { "B is TRUE" }));
            trueDatas.Add(Tuple.Create("", "B", new List<string>() { "B is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexOrTest05()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "B", new List<string>() { "B is TRUE" }));
            trueDatas.Add(Tuple.Create("", "B", new List<string>() { "B is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }
    }
}
