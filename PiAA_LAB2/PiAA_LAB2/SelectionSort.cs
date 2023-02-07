using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB2
{
    class SelectionSort
    {
        public SelectionSort(){ }

        public static int[] sort(int[] niz)
        {
            if (niz == null)
                return null;

            int imin,p;
            for (int i=0;i<niz.Length-1;i++)
            {
                imin = i;
                for(int j=i+1;j<niz.Length;j++)
                {
                    if (niz[j] < niz[imin])
                        imin = j;
                }
                p = niz[i];
                niz[i] = niz[imin];
                niz[imin] = p;
                
            }
            return niz;
        }

    }
}
