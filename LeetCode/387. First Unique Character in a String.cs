using System;
using System.Collections;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.Linq;


class Program
{
    static public int FirstUniqChar(string s)
    {
        Dictionary<char, int> koko = new Dictionary<char, int>();

        foreach (char c in s)
        {
            if (koko.ContainsKey(c))
                koko[c]++;
            else
                koko[c] = 1;
        }

        for (int i = 0; i < s.Length; i++)
        {
            if (koko[s[i]] == 1)
                return i;
        }

        return -1;
    }


    static void Main()
    {
        Console.WriteLine(FirstUniqChar("loveleetcode"));
    }


}
