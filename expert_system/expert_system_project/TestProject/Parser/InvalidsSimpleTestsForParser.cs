using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System.IO;

namespace TestProject
{
    [TestClass]
    public class InvalidsSimpleTestsForParser
    {
        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse01()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse02()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(BonusError), "")]
        public void TestInvalidSimpleParse03()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse04()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse05()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse06()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse07()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/07Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse08()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/08Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse09()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/09Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse10()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/10Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse11()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/11Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse12()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/12Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(BonusError), "")]
        public void TestInvalidSimpleParse13()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/13Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse14()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/14Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse15()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/15Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse16()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/16Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse17()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/17Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse18()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/18Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse19()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/19Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse20()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/20Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse21()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/21Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse22()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/22Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse23()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/23Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse24()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/24Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse25()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/25Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse26()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/26Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(ExceptionSyntaxError), "")]
        public void TestInvalidSimpleParse27()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/27Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }

        [TestMethod]
        [ExpectedException(typeof(BonusError), "")]
        public void TestInvalidSimpleParse28()
        {
            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/invalidsTests/28Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
        }
    }
}
