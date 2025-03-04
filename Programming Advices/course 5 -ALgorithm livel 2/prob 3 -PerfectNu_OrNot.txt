#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadPositiveNumber(string msg)
{
    float Number = 0;
    do
    {
        cout << msg << endl;
        cin >> Number;
    } while (Number <= 0);
    
    return Number; 
}

bool IsPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
        {
            Sum += i;
        }
    }
    return Sum == Number;
}

void PrintResult(int Number)
{
    if (IsPerfectNumber(Number))
        cout << "Perfect" << endl;
    else 
        cout << "Not Perfect" << endl;
    
}

int main()
{
    
    PrintResult(ReadPositiveNumber("Please Enter Number : "));
    
    
    return 0;
}