using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class ComplexAndTestsForSolver
    {
        private string folder = @"testFiles/testSolver/complexTests/testsAnd/";

        [TestMethod]
        public void ComplexAndTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("E", "F", new List<string>() { "F is FALSE" }));
            trueDatas.Add(Tuple.Create("ABCDE", "F", new List<string>() { "F is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexAndTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("FG", "H", new List<string>() { "H is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexAndTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABCDEFG", "H", new List<string>() { "H is TRUE" }));
            trueDatas.Add(Tuple.Create("ABCEFG", "H", new List<string>() { "H is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexAndTest04()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABEG", "H", new List<string>() { "H is TRUE" }));
            trueDatas.Add(Tuple.Create("AEG", "H", new List<string>() { "H is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexAndTest05()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABDEGHJK", "M", new List<string>() { "M is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexAndTest06()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("ABDEGHJK", "O", new List<string>() { "O is TRUE" }));
            trueDatas.Add(Tuple.Create("O", "O", new List<string>() { "O is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

        [TestMethod]
        public void ComplexAndTest07()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("N", "OPQ", new List<string>() { "O is TRUE", "P is TRUE", "Q is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "07Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            if (!(Analyzer.Analyse(trueDatas, results)))
                Assert.Fail();
        }

    }
}
