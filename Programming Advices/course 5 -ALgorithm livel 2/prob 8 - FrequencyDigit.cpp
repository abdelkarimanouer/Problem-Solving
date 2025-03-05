#include <iostream>
#include <cmath>
#include <string>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    int Number = 0;
    do
    {
        cout << Msg;
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
        
        if (Remainder == Digit)
        { 
            Frequency++;
            
        }    
    }
    
    return Frequency;
    
}

int main()
{ 
    int Number = ReadPositiveNumber("Please Enter Number :");
    short Digit = ReadPositiveNumber("Please Enter check Digit Number : ");

    cout << "\nDigit " << Digit << " frequency is " << FrequencyNumber(Number, Digit) << " Time." << endl;

    return 0;
}