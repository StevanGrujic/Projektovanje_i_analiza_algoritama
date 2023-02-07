using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB1
{
    class Rabin_Karp
    {
        public Rabin_Karp() { }

        public static void FindMatches(string Tekst, string Pattern, int brRazlKaraktera, long max,string fileName)
        {
            int length = Tekst.Length;
            int plength = Pattern.Length;
            long code = 0;
            long trenCode = 0;
            char[] niz1 = new char[length];
            char[] niz2 = new char[plength];
            int k;
            niz1 = Tekst.ToCharArray();
            niz2 = Pattern.ToCharArray();
            for (int i = 0; i < plength; i++)
            {
                code += (niz2[i] * ((long)Math.Pow(brRazlKaraktera, plength - i - 1)));
                trenCode += (niz1[i] * (long)Math.Pow(brRazlKaraktera, plength - i - 1));
            }
            using (StreamWriter sw = new StreamWriter(fileName))
            {

                for (int i = 0; i < length - plength; i++)
                {
                    if (code == trenCode)
                    {
                        k = 0;
                        for (int j = 0; j < plength; j++)
                        {
                            if (niz2[j] != niz1[i + k])
                            {
                                break;
                            }
                            k++;
                        }
                        if (k == plength)
                        {
                            sw.WriteLine(Pattern);
                        }
                    }
                    trenCode = ((trenCode - (niz1[i] * (long)Math.Pow(brRazlKaraktera, plength - 1))) * brRazlKaraktera + niz1[i + plength]);
                }
            }
        }


    }
    /*public class RabinKarp
    {
        public static int d = 10;

        public static void search(string txt, string pattern, int q)
        {
            int m = pattern.Length;
            int n = txt.Length;
            int i, j;
            int p = 0;
            int t = 0;
            int h = 1;

            for (i = 0; i < m - 1; i++)
                h = (h * d) % q;

            // Calculate hash value for pattern and text
            for (i = 0; i < m; i++)
            {
                p = (d * p + pattern.ElementAt(i)) % q;
                t = (d * t + txt.ElementAt(i)) % q;
            }

            // Find the match
            for (i = 0; i <= n - m; i++)
            {
                if (p == t)
                {
                    for (j = 0; j < m; j++)
                    {
                        if (txt.ElementAt(i + j) != pattern.ElementAt(j))
                            break;
                    }

                    if (j == m)
                        Console.WriteLine(pattern);
                }

                if (i < n - m)
                {
                    t = (d * (t - txt.ElementAt(i) * h) + txt.ElementAt(i + m)) % q;
                    if (t < 0)
                        t = (t + q);
                }
            }
        }
    }*/
}
