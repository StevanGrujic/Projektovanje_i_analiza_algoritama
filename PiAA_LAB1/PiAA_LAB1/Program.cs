using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace PiAA_LAB1
{
    class Program
    {
        static void Main(string[] args)
        {
            string Tekst1;
            Stopwatch sw = new Stopwatch();
            using (StreamReader sr = new StreamReader("C:\\Users\\WinWin\\Desktop\\Hexa_100.txt"))
            {
                Tekst1 = sr.ReadToEnd();

                sw.Start();
                Rabin_Karp.FindMatches(Tekst1, "4d90b", 16, Int32.MaxValue, "Rabin_Karp_Hexa_5" + ".txt"); //5
                sw.Stop();
                Console.WriteLine("RabinKarp_5_Hexa_100" +"_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Knuth_Morris_Pratt.FindMatches(Tekst1, "4d90bb6ab7", "Knuth_Morris_Pratt_Hexa_10_" + ".txt"); //10
                sw.Stop();
                Console.WriteLine("Knuth_Morris_Pratt_10_Hexa_100" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                SoundEx.matches(Tekst1, "6a4428d95bd544d90bb6", "SoundEx_Hexa_20" + ".txt"); //20
                sw.Stop();
                Console.WriteLine("SoundEx_20_Hexa_100" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Levenshtein.matches(Tekst1, "4d90bb6ab7d593fadae6c9492c455ec96df539d5fa4d3a8533", "Levenshtein_Hexa_50"+ ".txt"); //5
                sw.Stop();
                Console.WriteLine("Levenshtein_50_Hexa_100" + "_Elapsed ={0}", sw.Elapsed);

            }
            using (StreamReader sr1 = new StreamReader("C:\\Users\\WinWin\\Desktop\\Hexa_10000.txt"))
            {
                Tekst1 = sr1.ReadToEnd();

                sw.Reset();
                sw.Start();
                Knuth_Morris_Pratt.FindMatches(Tekst1, "baf45", "Knuth_Morris_Pratt_Hexa_5" + ".txt"); //5
                sw.Stop();
                Console.WriteLine("Knuth_Morris_Pratt_5_Hexa_10000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Rabin_Karp.FindMatches(Tekst1, "baf4526304", 16, Int32.MaxValue, "Rabin_Karp_Hexa_10" + ".txt");//10
                sw.Stop();
                Console.WriteLine("RabinKarp_10_Hexa_10000" + "_Elapsed ={0}", sw.Elapsed);


                sw.Reset();
                sw.Start();
                Levenshtein.matches(Tekst1, "23b8f65c07648927072c", "Levenshtein_Hexa_20" + ".txt"); //20
                sw.Stop();
                Console.WriteLine("Levenshtein_20_Hexa_10000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                SoundEx.matches(Tekst1, "8c6c4a509ba28da9c49e31d92326fe4d906db4061b06021e3a", "SoundEx_Hexa_50" + ".txt"); //50
                sw.Stop();
                Console.WriteLine("SoundEx_50_Hexa_10000" + "_Elapsed ={0}", sw.Elapsed);
            }

            using (StreamReader sr2 = new StreamReader("C:\\Users\\WinWin\\Desktop\\Tekst_1000.txt"))
            {
                Tekst1 = sr2.ReadToEnd();


                sw.Reset();
                sw.Start();
                SoundEx.matches(Tekst1, "velit", "SoundEx_Text_5" + ".txt"); //5
                sw.Stop();
                Console.WriteLine("SoundEx_5_Text_1000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Levenshtein.matches(Tekst1, "consectetu", "Levenshtein_Text_10" + ".txt"); //10
                sw.Stop();
                Console.WriteLine("Levenshtein_10_Text_1000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Knuth_Morris_Pratt.FindMatches(Tekst1, "Lorem ipsum dolor si", "Knuth_Morris_Pratt_Text_20" + ".txt"); //20
                sw.Stop();
                Console.WriteLine("Knuth_Morris_Pratt_20_Text_1000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Rabin_Karp.FindMatches(Tekst1, "facilisis rhoncus diam. Vestibulum sed diam porta o", 256, Int64.MaxValue, "Rabin_Karp_Text_50" + ".txt"); //50
                sw.Stop();
                Console.WriteLine("RabinKarp_50_Text_1000" + "_Elapsed ={0}", sw.Elapsed);

            }
            using (StreamReader sr3 = new StreamReader("C:\\Users\\WinWin\\Desktop\\Tekst_100000.txt"))
            {
                Tekst1 = sr3.ReadToEnd();

                sw.Reset();
                sw.Start();
                Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Text_5" + ".txt"); //10
                sw.Stop();
                Console.WriteLine("Levenshtein_5_Text_100000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                SoundEx.matches(Tekst1, "consectetu", "SoundEx_Text_10" + ".txt"); //5
                sw.Stop();
                Console.WriteLine("SoundEx_10_Text_100000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Rabin_Karp.FindMatches(Tekst1, "lacus eget eros plac", 256, Int64.MaxValue, "Rabin_Karp_Text_20" + ".txt"); //50
                sw.Stop();
                Console.WriteLine("RabinKarp_20_Text_100000" + "_Elapsed ={0}", sw.Elapsed);

                sw.Reset();
                sw.Start();
                Knuth_Morris_Pratt.FindMatches(Tekst1, "Aliquam tempus commodo augue id commodo. Proin pur", "Knuth_Morris_Pratt_Text_50" + ".txt"); //20
                sw.Stop();
                Console.WriteLine("Knuth_Morris_Pratt_50_Text_100000" + "_Elapsed ={0}", sw.Elapsed);
            }

            /* string P = "Nullam";
             string Tekst1;
             Stopwatch sw = new Stopwatch();

             string[] fileNames = {  "C:\\Users\\WinWin\\Desktop\\Tekst_100.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Tekst_1000.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Tekst_10000.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Tekst_100000.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Hexa_100.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Hexa_1000.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Hexa_10000.txt",
                                     "C:\\Users\\WinWin\\Desktop\\Hexa_100000.txt"
             };
             int k = 100;
             int s = 100;
             foreach(string fileName in fileNames)
             {
                 using (StreamReader sr = new StreamReader(fileName))
                 {
                     Tekst1 = sr.ReadToEnd();
                     if (fileName.Contains("Tekst"))
                     {
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1,"Nullam", 256, Int32.MaxValue, "Rabin_Karp_Tekst_5_"+k+".txt"); //5
                         sw.Stop();
                         Console.WriteLine("RabinKarp_5_Text_"+k+"_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, "Pellentesque", 256, Int32.MaxValue, "Rabin_Karp_Tekst_10_" + k + ".txt"); //10
                         sw.Stop();
                         Console.WriteLine("RabinKarp_10_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, P, 256, Int32.MaxValue, "Rabin_Karp_Tekst_20_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("RabinKarp_20_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, P, 256, Int32.MaxValue, "Rabin_Karp_Tekst_50_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("RabinKarp_50_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, "Nullam","Knuth_Morris_Pratt_Tekst_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_5_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, "Phassellus", "Knuth_Morris_Pratt_Tekst_10_" + k + ".txt"); //10
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_10_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, P, "Knuth_Morris_Pratt_Tekst_20_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_20_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, P, "Knuth_Morris_Pratt_Tekst_50_" + k + ".txt"); //50
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_50_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "Nollem", "SoundEx_Tekst_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("SoundEx_5_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "sit", "SoundEx_Tekst_10_" + k + ".txt"); //10
                         sw.Stop();
                         Console.WriteLine("SoundEx_10_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "sit", "SoundEx_Tekst_20_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("SoundEx_20_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "sit", "SoundEx_Tekst_50_" + k + ".txt"); //50
                         sw.Stop();
                         Console.WriteLine("SoundEx_50_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Tekst_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_5_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Tekst_10_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_10_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Tekst_20_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_20_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Tekst_50_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_50_Text_" + k + "_Elapsed ={0}", sw.Elapsed);

                         k *= 10;
                     }
                     else
                     {
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, "Nullam", 256, Int32.MaxValue, "Rabin_Karp_Hexa_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("RabinKarp_5_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, "Pellentesque", 256, Int32.MaxValue, "Rabin_Karp_Hexa_10_" + k + ".txt"); //10
                         sw.Stop();
                         Console.WriteLine("RabinKarp_10_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, P, 256, Int32.MaxValue, "Rabin_Karp_Hexa_20_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("RabinKarp_20_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Rabin_Karp.FindMatches(Tekst1, P, 256, Int32.MaxValue, "Rabin_Karp_Hexa_50_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("RabinKarp_50_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, "Nullam", "Knuth_Morris_Pratt_Hexa_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_5_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, "Phassellus", "Knuth_Morris_Pratt_Hexa_10_" + k + ".txt"); //10
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_10_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, P, "Knuth_Morris_Pratt_Hexa_20_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_20_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Knuth_Morris_Pratt.FindMatches(Tekst1, P, "Knuth_Morris_Pratt_Hexa_50_" + k + ".txt"); //50
                         sw.Stop();
                         Console.WriteLine("Knuth_Morris_Pratt_50_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "Nollem", "SoundEx_Hexa_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("SoundEx_5_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "sit", "SoundEx_Hexa_10_" + k + ".txt"); //10
                         sw.Stop();
                         Console.WriteLine("SoundEx_10_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "sit", "SoundEx_Hexa_20_" + k + ".txt"); //20
                         sw.Stop();
                         Console.WriteLine("SoundEx_20_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         SoundEx.matches(Tekst1, "sit", "SoundEx_Hexa_50_" + k + ".txt"); //50
                         sw.Stop();
                         Console.WriteLine("SoundEx_50_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Hexa_5_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_5_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Hexa_10_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_10_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Hexa_20_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_20_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);

                         sw.Reset();
                         sw.Start();
                         Levenshtein.matches(Tekst1, "mamut", "Levenshtein_Hexa_50_" + k + ".txt"); //5
                         sw.Stop();
                         Console.WriteLine("Levenshtein_50_Hexa_" + k + "_Elapsed ={0}", sw.Elapsed);
                         s *= 10;
                     }
                 }
             }*/
        }
    }
}
