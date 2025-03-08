using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    static public int NumIdenticalPairs(int[] nums)
    {
        int count = 0;

        for (int i = 0; i < nums.Length; i++)
        {
            for (int j = i + 1; j < nums.Length; j++)
            {
                if (nums[i] == nums[j])
                {
                    count++;
                }
            }
        }

        return count;
    }

    static void Main()
    {
        int[] nums = {1, 2, 3, 1, 1, 3};

        Console.WriteLine( NumIdenticalPairs(nums) );
    }
}
