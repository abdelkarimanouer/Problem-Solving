#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    int Number = 0;
    do
    {
        cout << Msg << endl;
        cin >> Number;
    } while (Number <= 0);

    return Number;   
}

int SumDigits(int Number)
{
    int Remainder = 0;
    int Sum = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        
        Sum += Remainder;
    }
    return Sum;  
    
}

int main()
{ 

    cout << SumDigits(ReadPositiveNumber("Please Enter Number : ")) << endl;

    return 0;
}