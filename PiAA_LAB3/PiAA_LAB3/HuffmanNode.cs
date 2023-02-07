using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB3
{
    class HuffmanNode
    {

        public HuffmanNode(int a)
        {
            this.Ucestalost = a;
            this.Code = "";
            this.Parent = null;
            this.Karakter = '\0';
        }
        public HuffmanNode(char c, int a)
        {
            this.Karakter = c;
            this.Ucestalost = a;
            this.Code = "";
            this.Parent = null;
        }
        public HuffmanNode(char c, int a,HuffmanNode parent)
        {
            this.Karakter = c;
            this.Ucestalost = a;
            this.Code = "";
            this.Parent = parent;
        }
        public HuffmanNode(char c, int a , string s,HuffmanNode parent)
        {
            this.Karakter = c;
            this.Ucestalost = a;
            this.Code = s;
            this.Parent = parent;
        }
        public char Karakter { get; set; }

        public int Ucestalost { get; set; }

        public string Code { get; set; }

        public HuffmanNode Parent { get; set; }
        public HuffmanNode Left { get; set; }
        public HuffmanNode Right { get; set; }
    }
}
