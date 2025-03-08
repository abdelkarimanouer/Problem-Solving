using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static bool IsStringUnique(string s)
    {
        if (string.IsNullOrWhiteSpace(s))
        {
            return false;
        }

        HashSet<char> hs = new HashSet<char>();

        foreach (var c in s.ToLower())
        {
            if (!hs.Add(c))
            {
                return false;
            }
        }

        return true;
    }

    static void Main()
    {
        string s = "Leetcode";
        Console.WriteLine( IsStringUnique(s) );
    }
}
