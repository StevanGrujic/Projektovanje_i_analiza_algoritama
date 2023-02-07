using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Diagnostics;

namespace PiAA_LAB3
{
    class Program
    {
        static void Main(string[] args)
        {

            string b = @"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque scelerisque nunc lacus, et tincidunt urna sagittis tristique. Suspendisse auctor pellentesque luctus. Integer rhoncus erat in mauris tincidunt, at interdum tortor semper. Nullam feugiat suscipit ipsum, eu porta nulla ornare et. Sed quis eleifend turpis. Phasellus convallis nulla in iaculis ornare. Integer facilisis magna quis turpis ultricies commodo. Vestibulum ex lacus, blandit vel viverra nec, mattis id nunc. Curabitur consectetur massa vel cursus lobortis.

Suspendisse sed diam ante. Nunc pellentesque bibendum nunc at scelerisque. Fusce vitae erat sodales, scelerisque massa nec, iaculis ipsum.Sed nunc nunc, dictum et vestibulum id, dignissim vitae est. Sed scelerisque molestie eros eget ultricies. Vestibulum diam nisl, vulputate ut egestas sit amet, consectetur vitae urna.Pellentesque quis efficitur nulla. Pellentesque auctor sagittis malesuada. Nullam id interdum augue, at vehicula nibh. Sed ex augue, vulputate in arcu eu, ultrices feugiat diam. Lorem ipsum dolor sit amet, consectetur adipiscing elit.Fusce non libero nec sapien rutrum luctus.

Phasellus porttitor sapien mi, ac malesuada felis sollicitudin ac. Etiam quis convallis dui, at imperdiet mauris. Mauris vehicula purus lacus, at placerat felis euismod vel. Fusce pharetra elit nibh, in venenatis libero cursus a. Sed eget augue at augue elementum dapibus.Sed quis purus dui. Fusce leo mi, sodales eget blandit convallis, ultricies quis urna.

Donec faucibus id metus id molestie. Etiam massa ex, vestibulum lacinia velit vel, mattis ullamcorper urna. Etiam vitae vulputate lacus. Vivamus semper, neque eu gravida maximus, purus nibh luctus purus, et faucibus sem est eget metus.Fusce volutpat orci ac quam euismod, id porttitor quam molestie.Cras consectetur felis vitae convallis ornare. Proin fringilla magna libero, sollicitudin ultricies dui pulvinar pellentesque. Sed sed dignissim arcu. Morbi quis nunc rhoncus, varius ex quis, tempus sapien.";
            Stopwatch sw = new Stopwatch();

            sw.Start();
            Shannon_Fano.CodeTable(b);
            sw.Stop();
            Console.WriteLine("Vreme izvrsenja Shannon_Fano algoritma je: "+sw.Elapsed);

            sw.Reset();
            sw.Start();
            Huffman.CodeTable(b);
            sw.Stop();
            Console.WriteLine("Vreme izvrsenja Huffman algoritma je: " + sw.Elapsed);
        }
    }
}
