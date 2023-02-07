using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB3
{
    class Node
    {

        public Node(Dictionary<char,int> dic,Node parent)
        {
            this.Map = dic;
            this.Code = "";
            this.Left = null;
            this.Right = null;
            this.Parent = parent;
        }

        public Node(Dictionary<char, int> dic,string code)
        {
            this.Map = dic;
            this.Code = code;
            this.Left = null;
            this.Right = null;
        }
        public Node(Dictionary<char,int> dic,string code, Node left, Node right)
        {
            this.Map = dic;
            this.Code = code;
            this.Left = left;
            this.Right = right;
        }

        public Node Parent { get; set; }
        public Node Left { get; set; }

        public Node Right { get; set; }
        public Dictionary<char,int> Map { get; set; }

        public string Code { get; set; }
    }
}
