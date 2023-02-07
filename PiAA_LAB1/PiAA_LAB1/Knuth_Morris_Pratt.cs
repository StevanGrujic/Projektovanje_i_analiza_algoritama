using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB1
{
    class Knuth_Morris_Pratt
    {
        public Knuth_Morris_Pratt() { }

        public static void FindMatches(string Tekst, string Pattern,string fileName)
        {
            int j = 0;
            int k = 0;
            int[] lps = new int[Pattern.Length + 1];
            char[] nizPattern = new char[Pattern.Length];
            char[] nizTekst = new char[Tekst.Length];
            nizTekst = Tekst.ToCharArray();
            nizPattern = Pattern.ToCharArray();
            lps[0] = 0;
            //Kreiranje lps niza
            for (int i = 1; i < Pattern.Length; i++)
            {
                if (nizPattern[i] == nizPattern[lps[i - 1]])
                {
                    lps[i] = lps[i - 1] + 1;
                }
                else if (nizPattern[i] == nizPattern[0])
                {
                    lps[i] = 1;
                }
                else
                {
                    lps[i] = 0;
                }
            }
            bool inc = false;
            using (StreamWriter sw = new StreamWriter(fileName))
            {

                while (k < nizTekst.Length)
                {
                    while (j < Pattern.Length && nizPattern[j] == nizTekst[k])
                    {
                        j++;
                        k++;
                        inc = true;
                    }
                    if (j == Pattern.Length)
                    {
                        //Console.WriteLine(Pattern);
                        sw.WriteLine(Pattern);
                        j = 0;
                    }
                    else
                    {
                        j = lps[j];
                    }
                    if (!inc)
                    {
                        k++;
                    }
                    inc = false;
                }
            }

        }
    }
}
