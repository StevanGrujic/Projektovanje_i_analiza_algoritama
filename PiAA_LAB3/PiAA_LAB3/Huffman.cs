using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB3
{
    class Huffman
    {
        public Huffman()
        {
            this.Root = null;
        }
        public Huffman(HuffmanNode root)
        {
            this.Root = root;
        }
        public HuffmanNode Root { get; set; }
        public static Dictionary<char, int> prebroj(string s)
        {
            Dictionary<char, int> map = new Dictionary<char, int>();
            char[] niz = s.ToCharArray();
            foreach (char el in niz)
            {
                if (!map.ContainsKey(el))
                {
                    map.Add(el, 0);
                }
            }
            foreach (char el in niz)
            {
                map[el]++;
            }
            return map;
        }

        public static List<HuffmanNode> formNodes(Dictionary<char,int> dic)
        {
            List<HuffmanNode> nodeList = new List<HuffmanNode>(dic.Count);
            foreach(char c in dic.Keys)
            {
                nodeList.Add(new HuffmanNode(c, dic[c]));
            }
            return nodeList;
        }

        public static void formTree(ref List<HuffmanNode> nodes)
        {
            if(nodes.Count==1)
            {
                return;
            }
            nodes = nodes.OrderBy(node => node.Ucestalost).ToList();
            HuffmanNode Pnode = new HuffmanNode(nodes[0].Ucestalost+nodes[1].Ucestalost);
            Pnode.Left = nodes[0];
            Pnode.Right = nodes[1];
            nodes[0].Parent = Pnode;
            nodes[1].Parent = Pnode;
            nodes.RemoveAt(0);
            nodes.RemoveAt(0);
            nodes.Add(Pnode);
            nodes = nodes.OrderBy(node => node.Ucestalost).ToList();
            formTree(ref nodes);
        }
        public static void dodeliKodove(HuffmanNode node)
        {
            if(node==null && node==null)
            {
                return;
            }

            if (node.Parent == null)
            {
                node.Code = "";
            }
            else
            {
                if(node==node.Parent.Left)
                {
                    node.Code = node.Parent.Code + "0";
                }
                else
                {
                    node.Code = node.Parent.Code + "1";
                }
            }
            dodeliKodove(node.Left);
            dodeliKodove(node.Right);

        }
        public static void formTable(HuffmanNode node)
        {
            if (node.Left == null && node.Right == null)
            {
                Console.WriteLine(node.Karakter + " " + node.Code);
                return;
            }
            formTable(node.Left);
            formTable(node.Right);
        }
        public static void CodeTable(string s)
        {
            List<HuffmanNode> nodes = new List<HuffmanNode>();
            nodes = Huffman.formNodes(Huffman.prebroj(s));
            Huffman.formTree(ref nodes);
            Huffman.dodeliKodove(nodes[0]);
            Huffman.formTable(nodes[0]);
            int suma = 0;
            Huffman.Count(nodes[0], ref suma);
            Console.WriteLine("Potrebno je " + suma + " bitova");
        }
        public static void Count(HuffmanNode node, ref int suma)
        {
            if (node == null)
            {
                return;
            }
            if (node.Left == null && node.Right == null)
            {
                suma += node.Ucestalost * node.Code.Length;
            }
            Count(node.Left, ref suma);
            Count(node.Right, ref suma);
        }
    }
}
