#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    int Number = 0;
    do
    {
        cout << Msg ;
        cin >> Number;
    } while (Number <= 0);

    return Number;   
}

int ReversedNumber(int Number)
{
    int Remainder = 0;
    int Number2 = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        
        Number2 = Number2 * 10 + Remainder;

    }  
    return Number2;
}

void PrintDigits(int Number)
{
    int Remainder = 0;
    
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        
        cout << Remainder << endl;
    } 
    
}

int main()
{ 

    PrintDigits(ReversedNumber(ReadPositiveNumber("Please Enter Number : ")));

    return 0;
}