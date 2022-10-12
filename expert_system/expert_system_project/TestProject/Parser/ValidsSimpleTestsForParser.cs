using ExpertSystem;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace TestProject
{
    [TestClass]
    public class ValidsSimpleTestsForParser
    {
        [TestMethod]
        public void TestValidSimpleParse01()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('D');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '(', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '|', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = ')', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'D', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/01Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse02()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('D');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '(', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '!', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '|', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = ')', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'D', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/02Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse03()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');
            trueFacts.Add('D');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('E');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '(', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '!', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '|', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '(', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '|', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'D', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = ')', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = ')', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'E', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/03Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse04()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');
            trueFacts.Add('D');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('E');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = '(', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '!', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = ')', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '|', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '(', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '|', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'D', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = ')', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'E', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/04Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse05()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('C');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/05Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse06()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');
            trueFacts.Add('=');
            trueFacts.Add('=');
            trueFacts.Add('D');
            trueFacts.Add('E');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('C');
            trueQuerries.Add('?');
            trueQuerries.Add('E');
            trueQuerries.Add('?');
            trueQuerries.Add('C');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = true });
            trueDatas.Add(new Data { nom = 'D', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'E', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'F', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/06Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse07()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');
            trueFacts.Add('=');
            trueFacts.Add('B');
            trueFacts.Add('C');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('C');
            trueQuerries.Add('?');
            trueQuerries.Add('C');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/07Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse08()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('C');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/08Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas
            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }

        [TestMethod]
        public void TestValidSimpleParse09()
        {
            //Definition des true facts
            var trueFacts = new List<char>();
            trueFacts.Add('=');
            trueFacts.Add('A');
            trueFacts.Add('B');
            trueFacts.Add('C');

            //Definitions des true querries
            var trueQuerries = new List<char>();
            trueQuerries.Add('?');
            trueQuerries.Add('D');

            //Definition des true datas
            var trueDatas = new List<Data>();
            trueDatas.Add(new Data { nom = 'A', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'B', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '+', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'C', type = true, value = false, eol = false });
            trueDatas.Add(new Data { nom = '1', type = false, value = false, eol = false });
            trueDatas.Add(new Data { nom = 'D', type = true, value = false, eol = true });

            //Recuperation du fichier de test et lexing/parsing
            string[] lines = File.ReadAllLines(@"testFiles/testParser/validsTests/09Test.txt");
            var lexered = Lexer.CheckThatFile(lines); //check du fichier
            var parsered = Parser.Parse(lexered); //check des datas

            var testDatas = parsered.Item1;
            var testFacts = parsered.Item2;
            var testQuerries = parsered.Item3;

            if (!(testDatas.SequenceEqual(testDatas)))
                Assert.Fail();
            if (!(testFacts.SequenceEqual(trueFacts)))
                Assert.Fail();
            if (!(testQuerries.SequenceEqual(trueQuerries)))
                Assert.Fail();
        }
    }
}
