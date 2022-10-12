using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class MixedTestsForSolver
    {
        private string folder = @"testFiles/testSolver/complexTests/testsMixed/";

        [TestMethod]
        public void MixedTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("C", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), false); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("BC", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("AC", "D", new List<string>() { "D is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("A", "D", new List<string>() { "D is FALSE" }));
            trueDatas.Add(Tuple.Create("B", "D", new List<string>() { "D is FALSE" }));
            trueDatas.Add(Tuple.Create("C", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("D", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest04()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("A", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("C", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("D", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest05()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("A", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("B", "D", new List<string>() { "D is TRUE" }));
            trueDatas.Add(Tuple.Create("C", "D", new List<string>() { "D is FALSE" }));
            trueDatas.Add(Tuple.Create("D", "D", new List<string>() { "D is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest06()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABDEF", "G", new List<string>() { "G is TRUE" }));
            trueDatas.Add(Tuple.Create("ABC", "G", new List<string>() { "G is FALSE" }));
            trueDatas.Add(Tuple.Create("AF", "G", new List<string>() { "G is FALSE" }));
            trueDatas.Add(Tuple.Create("ABD", "G", new List<string>() { "G is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest07()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("G", "AB", new List<string>() { "A is TRUE", "B is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "07Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void MixedTest08()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("G", "ABC", new List<string>() { "A is TRUE", "B is FALSE", "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "08Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        [ExpectedException(typeof(BonusError), "")]
        public void MixedTest09()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("G", "AB", new List<string>() { "A is TRUE", "B is FALSE"}));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "09Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            //if (!(Analyzer.Analyse(trueDatas, results)))
            //    Assert.Fail();
        }
    }
}
