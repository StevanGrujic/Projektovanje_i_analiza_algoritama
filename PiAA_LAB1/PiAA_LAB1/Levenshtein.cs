using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB1
{
    class Levenshtein
    {
        public Levenshtein() { }

        public static int minimum(int a, int b, int c)
        {
            return Math.Min(a, Math.Min(b, c));
        }
        public static int getDistance1(string A, string B, int lenA, int lenB)
        {
            if(lenA==0)
            {
                return lenB;
            }
            if(lenB==0)
            {
                return lenA;
            }

            int cost;
            if (A.ElementAt(lenA - 1) == B.ElementAt(lenB - 1))
                cost = 0;
            else
                cost = 1;

            return minimum(getDistance1(A, B, lenA, lenB - 1) + 1,//insert
                getDistance1(A, B, lenA - 1, lenB) + 1,//delete
                getDistance1(A, B, lenA - 1, lenB - 1) + cost);//replace
        }
        public static int getDistance(string A, int lenA, string B, int lenB)
        {
            int[,] matrica = new int[lenB + 1, lenA + 1];
            matrica[0, 0] = 0;
            char a, b;
            for(int i=1;i<=lenA;i++)
            {
                matrica[0,i] = matrica[0,i - 1] + 1;
            }
            for (int i = 1; i <= lenB; i++)
            {
                matrica[i, 0] = matrica[i-1, 0] + 1;
            }

            for(int i=1;i<=lenB;i++)
            {
                for(int j=1;j<=lenA;j++)
                {
                    if((a=A.ElementAt(j-1))==(b=B.ElementAt(i-1)))
                    {
                        matrica[i, j] = minimum(matrica[i - 1, j - 1], matrica[i - 1, j], matrica[i, j - 1]);
                    }
                    else
                    {
                        matrica[i, j] = minimum(matrica[i - 1, j - 1], matrica[i - 1, j], matrica[i, j - 1]) + 1;
                    }
                }
            }
            return matrica[lenB,lenA];
        }

        public static void matches(string Tekst, string Target,string fileName)
        {
            char[] delimiters = { ' ', '.', '!', '?', ':', ',' };
            string[] words = Tekst.Split(delimiters);
            using(StreamWriter sw = new StreamWriter(fileName))
            {

                foreach (string word in words)
                {
                    if(word.Length<=Target.Length+3 && word.Length>=Target.Length-3)
                    if (getDistance(word, word.Length, Target, Target.Length) <= 3)
                    {
                        sw.WriteLine(word);
                    }
                }
            }    
        }
    }
}
