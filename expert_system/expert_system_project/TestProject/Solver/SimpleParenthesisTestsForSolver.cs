using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace TestProject
{
    [TestClass]
    public class SimpleParenthesisTestsForSolver
    {
        private string folder = @"testFiles/testSolver/simpleTests/testsParenthesis/";

        [TestMethod]
        public void SimpleParenthesisTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest04()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest05()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest06()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest07()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "07Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest08()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "08Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest09()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "09Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest10()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "10Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest11()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "11Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest12()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "12Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest13()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "13Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest14()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABCD", "E", new List<string>() { "E is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "14Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest15()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABCD", "E", new List<string>() { "E is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "15Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest16()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABCD", "E", new List<string>() { "E is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "16Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void SimpleParenthesisTest17()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABCD", "E", new List<string>() { "E is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "17Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }
    }
}

