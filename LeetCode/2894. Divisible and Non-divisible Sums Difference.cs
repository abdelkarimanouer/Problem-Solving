using System;

class Program
{
    public static int DifferenceOfSums(int n, int m)
    {
        int Num1 = 0 ;
        int Num2 = 0 ;

        for (int i = 1; i <= n; i++)
        {
            if (i % m == 0)
            {
                Num2 += i;
            }
            else
            {
                Num1 += i;
            }
        }

        return (Num1 - Num2) ;
    }


    static void Main()
    {
        Console.WriteLine( DifferenceOfSums( 10, 3 ) );
    }
}

