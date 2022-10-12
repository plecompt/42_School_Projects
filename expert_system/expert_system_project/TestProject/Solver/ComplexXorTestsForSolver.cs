using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class ComplexXorTestsForSolver
    {
        private string folder = @"testFiles/testSolver/complexTests/testsXor/";

        [TestMethod]
        public void ComplexXorTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("C", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("AC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexXorTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("A", "F", new List<string>() { "F is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "F", new List<string>() { "F is TRUE" }));
            trueDatas.Add(Tuple.Create("C", "F", new List<string>() { "F is TRUE" }));
            trueDatas.Add(Tuple.Create("AC", "F", new List<string>() { "F is FALSE" }));
            trueDatas.Add(Tuple.Create("AE", "F", new List<string>() { "F is FALSE" }));
            trueDatas.Add(Tuple.Create("BE", "F", new List<string>() { "F is FALSE" }));
            trueDatas.Add(Tuple.Create("CE", "F", new List<string>() { "F is FALSE" }));
            trueDatas.Add(Tuple.Create("ACE", "F", new List<string>() { "F is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }
    }
}
