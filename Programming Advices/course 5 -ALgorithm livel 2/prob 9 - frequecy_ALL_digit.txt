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

int FrequencyNumber(int Number,short Digit)
{
    int Remainder = 0, Frequency = 0;
    
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        
        if (Digit == Remainder)
            Frequency++;    
    }
    
    return Frequency;
    
}

void PrintAllDigitsFrequency(int Number)
{
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        short AllDigits = 0;
        AllDigits = FrequencyNumber(Number, i);

        if (AllDigits > 0)
        {
            cout << "Digit " << i << " Frequency is " << AllDigits << " time(s)." << endl;
        }
    }
    
}

int main()
{ 
    int Number = ReadPositiveNumber("Please Enter Number :");
    
    PrintAllDigitsFrequency(Number);

    return 0;
}