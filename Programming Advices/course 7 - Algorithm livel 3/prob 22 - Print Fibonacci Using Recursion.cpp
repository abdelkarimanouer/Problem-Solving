#include <iostream>
#include <iomanip>
using namespace std;

void PrintFibonacciUsingRecursion(short Number,  int Prev1, int Prev2)
{   
    int FebNumber = 0;

    if (Number > 0)
    {
        FebNumber = Prev1 + Prev2;
        Prev2 = Prev1;
        Prev1 = FebNumber;        

        cout << FebNumber << "    ";
 
        PrintFibonacciUsingRecursion(Number - 1, Prev1, Prev2);        
    }
    
}

int main()
{     
    PrintFibonacciUsingRecursion(10, 0, 1);

    cout << endl;

    system("pause>0");
}

