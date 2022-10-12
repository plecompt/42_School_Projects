using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class ComplexParenthesisTestsForSolver
    {
        private string folder = @"testFiles/testSolver/complexTests/testsParenthesis/";

        [TestMethod]
        public void ComplexParenthesisTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "B", new List<string>() { "B is FALSE" }));
            trueDatas.Add(Tuple.Create("", "B", new List<string>() { "B is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexParenthesisTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "BC", new List<string>() { "B is FALSE", "C is TRUE" }));
            trueDatas.Add(Tuple.Create("", "BC", new List<string>() { "B is FALSE", "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexParenthesisTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "BC", new List<string>() { "B is TRUE", "C is TRUE" }));
            trueDatas.Add(Tuple.Create("", "BC", new List<string>() { "B is FALSE", "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }
    }
}
