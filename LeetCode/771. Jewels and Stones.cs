using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public static int NumJewelsInStones(string jewels, string stones)
    {
        int count = 0;
        HashSet<char> jewelSet = new HashSet<char>(jewels); 

        foreach (var s in stones) 
        {
            if (jewelSet.Contains(s)) 
            {
                count++;
            }
        }

        return count;
    }

    static void Main()
    {
        string jewels = "aA", stones = "aAAbbbb";

        Console.WriteLine(NumJewelsInStones(jewels, stones));
    }
}

