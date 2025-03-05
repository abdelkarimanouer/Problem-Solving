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

    PrintDigits(ReadPositiveNumber("Please Enter Number : "));

    return 0;
}