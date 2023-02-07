using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB2
{
    class RadixSort
    {
        public RadixSort() { }

        public static int[] CountingSort(int[] niz, int k, int placeValue)
        {
            int[] c = new int[k];
            int[] b = new int[niz.Length];
            int cifra;
            for (int i = 0; i < k; i++)
            {
                c[i] = 0;
            }
            for (int i = 0; i < niz.Length; i++)
            {
                cifra = (niz[i] / placeValue) % 10;
                c[cifra]++;
            }
            for(int i=1;i<k;i++)
            {
                c[i] = c[i - 1] + c[i];
            }
            for(int i=niz.Length-1;i>=0;i--)
            {
                cifra = (niz[i] / placeValue) % 10;
                b[c[cifra] - 1] = niz[i];
                c[cifra]--;
            }
            return b;
        }
        public static int nadjiMax(int[] niz)
        {
            int max=0;
            for(int i=0;i<niz.Length;i++)
            {
                if (niz[i] > max)
                    max = niz[i];
            }
            return max;
        }
        public static int brojCifara(int a)
        {
            int k = 0;
            while(a>0)
            {
                a /= 10;
                k++;
            }
            return k;
        }
        public static void sort(ref int[] niz)
        {
            int maximumNumber = nadjiMax(niz);
            int numberOfDigits = brojCifara(maximumNumber);
            int placeValue = 1;
            while (numberOfDigits-- > 0)
            {
                niz=CountingSort(niz,10001,placeValue);
                placeValue *= 10;
            }
        }
    }
}
