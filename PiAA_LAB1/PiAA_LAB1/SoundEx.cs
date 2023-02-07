using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PiAA_LAB1
{
    class SoundEx
    {
        public SoundEx() { }
        public static String getGode(String s)
        {
            if (s == "")
                return "0000";
            char[] x = s.ToUpper().ToCharArray();

            char firstLetter = x[0];

            //RULE [ 2 ]
            for (int i = 0; i < x.Length; i++)
            {
                switch (x[i])
                {
                    case 'B':
                    case 'F':
                    case 'P':
                    case 'V':
                        {
                            x[i] = '1';
                            break;
                        }

                    case 'C':
                    case 'G':
                    case 'J':
                    case 'K':
                    case 'Q':
                    case 'S':
                    case 'X':
                    case 'Z':
                        {
                            x[i] = '2';
                            break;
                        }

                    case 'D':
                    case 'T':
                        {
                            x[i] = '3';
                            break;
                        }

                    case 'L':
                        {
                            x[i] = '4';
                            break;
                        }

                    case 'M':
                    case 'N':
                        {
                            x[i] = '5';
                            break;
                        }

                    case 'R':
                        {
                            x[i] = '6';
                            break;
                        }

                    default:
                        {
                            x[i] = '0';
                            break;
                        }
                }
            }

            //Remove duplicates
            //RULE [ 1 ]
            String output = "" + firstLetter;

            //RULE [ 3 ]
            for (int i = 1; i < x.Length; i++)
                if (x[i] != x[i - 1] && x[i] != '0')
                    output += x[i];

            //RULE [ 4 ]
            output = output + "0000";
            return output.Substring(0, 4);
        }

        public static bool equalCodes(string s1, string s2)
        {
            if (getGode(s1) == getGode(s2))
                return true;
            return false;
        }

        public static void matches(string Tekst,string Pattern,string fileName)
        {
            char[] delimiters = { ' ', '.', '!', '?', ':', ',' };
            string[] words = Tekst.Split(delimiters);
            using(StreamWriter sw = new StreamWriter(fileName))
            {
                   
                foreach(string word in words)
                {
                        if (equalCodes(word, Pattern))
                            sw.WriteLine(word);
                }
            } 
        }
    }
}
