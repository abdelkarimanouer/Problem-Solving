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
    for (int i = 1 ; i < Number; i++)
    {
        if (IsPerfectNumber(i))
        {
            cout << i << " Is Perfect" << endl;
        }
    }  
    
}

int main()
{
    
    PrintResult(ReadPositiveNumber("Please Enter Number : "));
    
    
    return 0;
}