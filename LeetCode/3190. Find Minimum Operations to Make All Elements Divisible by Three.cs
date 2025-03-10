using System;

class Program
{
    public static int MinimumOperations(int[] nums)
    {
        int count = 0;

        for (int i = 0; i < nums.Length; i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else if ((nums[i] + 1) % 3 == 0 )
            {
                count++;
            }
            else if ((nums[i] - 1) % 3 == 0)
            {
                count++;
            }

        }

        return count;
    }


    static void Main()
    {
        int[] nums = { 1, 2, 3, 4 };

        Console.WriteLine(MinimumOperations(nums) );
    }
}

