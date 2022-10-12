using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class ComplexNotTestsForSolver
    {
        private string folder = @"testFiles/testSolver/complexTests/testsNot/";

        [TestMethod]
        public void ComplexNotTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AC", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexNotTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AC", "E", new List<string>() { "E is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexNotTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("", "C", new List<string>() { "C is FALSE" }));
            trueDatas.Add(Tuple.Create("A", "C", new List<string>() { "C is FALSE" }));
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexNotTest04()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "G", new List<string>() { "G is TRUE" }));
            trueDatas.Add(Tuple.Create("", "G", new List<string>() { "G is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexNotTest05()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "G", new List<string>() { "G is FALSE" }));
            trueDatas.Add(Tuple.Create("", "G", new List<string>() { "G is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexNotTest06()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "H", new List<string>() { "H is FALSE" }));
            trueDatas.Add(Tuple.Create("", "H", new List<string>() { "H is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }
    }
}
