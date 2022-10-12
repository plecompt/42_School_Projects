using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace TestProject
{
    [TestClass]
    public class SimpleNotTestsForSolver
    {
        private string folder = @"testFiles/testSolver/simpleTests/testsNot/";

        [TestMethod]
        public void SimpleNotTest01()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest02()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest03()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest04()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest05()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest06()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest07()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "07Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest08()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "08Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest09()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "09Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving
            
            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest10()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "10Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest11()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "11Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest12()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "12Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest13()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is TRUE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "13Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest14()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "14Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest15()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "15Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest16()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "16Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }

        [TestMethod]
        public void SimpleNotTest17()
        {
            //Datas 
            var trueDatas = new List<Tuple<string, string, List<string>>>();
            trueDatas.Add(Tuple.Create("AB", "C", new List<string>() { "C is FALSE" }));

            //Recuperation du fichier de test et solving
            string[] lines = File.ReadAllLines(folder + "17Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var results = Solver.Solve(parsered.Item1, Facts.ExtractFactsAndQuerries(parsered.Item2, "="), Facts.ExtractFactsAndQuerries(parsered.Item3, "?"), true); //solving

            for (int i = 0; i < trueDatas.Count; i++)
            {
                if (!(trueDatas[i].Item1 == results[0].Item1))
                    Assert.Fail();
                if (!(trueDatas[0].Item2 == results[0].Item2))
                    Assert.Fail();
                for (int j = 0; j < trueDatas[i].Item3.Count; j++)
                    if (!(trueDatas[0].Item3[j] == results[0].Item3[j]))
                        Assert.Fail();
            }
        }
    }
}
