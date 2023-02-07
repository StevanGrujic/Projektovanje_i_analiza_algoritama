using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB2
{
    class HeapSort
    {
        public HeapSort() { }

        public static int Left(int i)
        {
            return 2 * i + 1;
        }
        public static int Right(int i)
        {
            return 2 * i + 2;
        }
        public static void Heapify(int[] niz, int length, int i)
        {
            int p;
            int l = Left(i);
            int r = Right(i);
            if (i <= 0 && l >= length && r >= length)
                return;

            int max = i;
            if (l < length && niz[l] > niz[i])
            {
                max = l;
            }

            if(r<length && niz[r]>niz[max])
            {
                max = r;
            }

            if(max!=i)
            {
                p = niz[i];
                niz[i] = niz[max];
                niz[max] = p;
                Heapify(niz,length, max);
            }

        }
        public static void BuildHeap(int[] niz)
        {
            int l = niz.Length;
            for(int i=l/2-1;i>=0;i--)
            {
                Heapify(niz,niz.Length,i);
            }
        }
        public static void sort(int[] niz)
        {
            BuildHeap(niz);
            for (int i = niz.Length - 1; i >= 0; i--)
            {
                int temp = niz[0];
                niz[0] = niz[i];
                niz[i] = temp;
                Heapify(niz, i, 0);
            }
        }
    }
}
