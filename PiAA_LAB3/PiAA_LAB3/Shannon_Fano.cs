using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB3
{
    class Shannon_Fano
    {
        public Shannon_Fano()
        {
            this.Root = null;
        }
        public Shannon_Fano(Node root)
        {
            this.Root = root;
        }
        public Node Root { get; set; }

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

        public static int zbir(Dictionary<char, int> d)
        {
            int suma = 0;
            foreach (int a in d.Values)
            {
                suma += a;
            }
            return suma;
        }

        public static void formTree(ref Node node)
        {
            int suma = zbir(node.Map);
            int tren = 0;
            if (node.Map.Count == 1)
            {
                return;
            }
            Dictionary<char, int> deo1 = new Dictionary<char, int>();
            Dictionary<char, int> deo2 = new Dictionary<char, int>();
            foreach (char key in node.Map.Keys)
            {
                if(node.Map[key]>suma/2)
                {
                    deo2.Add(key, node.Map[key]);
                }
                else
                {

                    if (tren < suma / 2)
                    {
                        tren += node.Map[key];
                        deo1.Add(key, node.Map[key]);
                    }
                    else
                    {
                        tren += node.Map[key];
                        deo2.Add(key, node.Map[key]);
                    }
                }
            }
            Node Lnode = new Node(deo1, node);
            Lnode.Code = Lnode.Parent.Code + "0";
            Node Rnode = new Node(deo2, node);
            Rnode.Code = Rnode.Parent.Code + "1";
            node.Left = Lnode;
            node.Right = Rnode;
            formTree(ref Lnode);
            formTree(ref Rnode);

        }
        public static void formTable(Node node)
        {
            if (node.Left == null && node.Right == null)
            {
                foreach (char c in node.Map.Keys)
                {
                    Console.WriteLine(c + " " + node.Code);
                }
                return;
            }
            formTable(node.Left);
            formTable(node.Right);
        }

        public static void CodeTable(string a)
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            dic = Shannon_Fano.prebroj(a);
            Node n = new Node(dic, "");
            Shannon_Fano.formTree(ref n);
            Shannon_Fano.formTable(n);
            int suma = 0;
            Shannon_Fano.Count(n,ref suma);
            Console.WriteLine("Potrebno je " + suma + " bitova");
        }

        public static void Count(Node node, ref int suma)
        {
            if(node==null)
            {
                return;
            }
            if(node.Left==null && node.Right==null)
            {
               foreach(char c in node.Map.Keys)
                {
                    suma += node.Map[c] * node.Code.Length;
                }
            }
            Count(node.Left, ref suma);
            Count(node.Right,ref suma);
        }
    }
}
