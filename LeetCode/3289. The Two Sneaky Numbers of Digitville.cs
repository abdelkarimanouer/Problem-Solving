using System;
using System.Collections.Generic;
using System.Linq;

class Program
{
    public static int[] GetSneakyNumbers(int[] nums)
    {
        if (nums.Length <= 1)
        {
            return nums;
        }

        HashSet<int> SeenBefore = new HashSet<int>();
        HashSet<int> RepeateNums = new HashSet<int>();

        foreach (int n in nums)
        {
            if ( !SeenBefore.Add(n) )
            {
               RepeateNums.Add(n);
            }
        }

        return RepeateNums.ToArray();
    }

    static void Main()
    {
        int[] nums = { 0, 1, 1, 0 };

        int[] num2 = GetSneakyNumbers(nums);

        for (int i = 0; i < num2.Length; i++)
        {
            Console.Write(num2[i] + " ");
        }

    }
}
