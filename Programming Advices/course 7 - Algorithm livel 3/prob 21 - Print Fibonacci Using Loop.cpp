#include <iostream>
#include <iomanip>
using namespace std;

void PrintFibonacciUsingLoop(short Number)
{

    int Prev2 = 0, Prev1 = 1;
    int FebNumber = 0;

    cout << "1    ";

    for(int i = 2; i <= Number; i++)
    {
            FebNumber = Prev1 + Prev2;
            cout << FebNumber << "    ";
        
            Prev2 = Prev1;
            Prev1 = FebNumber;
    }
    cout << endl;

}

int main()
{
    PrintFibonacciUsingLoop(10);


    system("pause>0");
}

