using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB2
{
    class Program
    {
        //                      Performanse prema zauzetosti memorije:                           Performanse prema vremenu izvrsenja:   Best Case         Worst Case
        //Selection sort                        O(1)                                                                                     O(n^2)            O(n^2)                                                            
        //Heap sort                             O(1)                                                                                     O(nlogn)          O(nlogn)
        //Radix sort                            O(n+k)                                                                                   O(nk)             O(nk)


        public static void Print(int[] niz)
        {
            if(niz!=null)
            {
                for (int i = 0; i < niz.Length; i++)
                    Console.Write(niz[i] + " ");
                Console.WriteLine("\n");
            }
        }
        public static void generisiNiz(out int[] niz, int size)
        {
            if (size < 0)
                throw new Exception("Size mora da bude veci od 0");
            Random rand = new Random();
            niz = new int[size];
            for(int i=0;i<size;i++)
            {
                niz[i] = rand.Next(10001);
            }
        }
        static void Main(string[] args)
        {
            int[] niz;
            Stopwatch sw = new Stopwatch();

            generisiNiz(out niz, 100);
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
           // Print(niz);

            generisiNiz(out niz, 100);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
          //  Print(niz);

            generisiNiz(out niz, 100);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
           // Print(niz);

            generisiNiz(out niz, 1000);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 1000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
           // Print(niz);

            generisiNiz(out niz, 1000);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 1000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            //Print(niz);

            generisiNiz(out niz, 1000);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 1000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            //Print(niz);

            generisiNiz(out niz, 10000);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 10000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            //Print(niz);

            generisiNiz(out niz, 10000);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            //Print(niz);

            generisiNiz(out niz, 10000);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
           // Print(niz);

            //Ispod ove linije su testirani svi moguci slucajevi

            /*Stopwatch sw = new Stopwatch();
            generisiNiz(out niz, 100);
            Console.WriteLine("Niz od 100 elemenata pre sortiranja");
            Print(niz);
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: "+ sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 1000);
            Console.WriteLine("Niz od 1000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 1000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 10000);
            Console.WriteLine("Niz od 10000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 10000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 100000);
            Console.WriteLine("Niz od 100000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 1000000);
            Console.WriteLine("Niz od 1000000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 1 000 000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 10000000);
            Console.WriteLine("Niz od 10 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 100000000);
            Console.WriteLine("Niz od 100 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            SelectionSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 000 000 elemenata posle sortiranja (Selection sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            //==============HEAPSORT=======================================
            generisiNiz(out niz, 100);
            Console.WriteLine("Niz od 100 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 1000);
            Console.WriteLine("Niz od 1000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 1000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 10000);
            Console.WriteLine("Niz od 10000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 100000);
            Console.WriteLine("Niz od 100000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 1000000);
            Console.WriteLine("Niz od 1 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 1 000 000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 10000000);
            Console.WriteLine("Niz od 10 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 100000000);
            Console.WriteLine("Niz od 100 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            HeapSort.sort(niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 000 000 elemenata posle sortiranja (Heap sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            //*****************RADIX SORT***************************************************************
            generisiNiz(out niz, 100);
            Console.WriteLine("Niz od 100 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 1000);
            Console.WriteLine("Niz od 1000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 1000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 10000);
            Console.WriteLine("Niz od 10000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 100000);
            Console.WriteLine("Niz od 100000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 1000000);
            Console.WriteLine("Niz od 1000000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 1 000 000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 10000000);
            Console.WriteLine("Niz od 10 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 10 000 000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);

            generisiNiz(out niz, 100000000);
            Console.WriteLine("Niz od 100 000 000 elemenata pre sortiranja");
            Print(niz);
            sw.Reset();
            sw.Start();
            RadixSort.sort(ref niz);
            sw.Stop();
            Console.WriteLine("Niz od 100 000 000 elemenata posle sortiranja (Radix sort). Vreme izvrsavanja: " + sw.Elapsed);
            Print(niz);*/

        }
    }
}
