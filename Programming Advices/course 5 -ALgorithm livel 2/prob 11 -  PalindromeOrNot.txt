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

bool IsPalindromeNumber(int Number)
{
    return Number == ReversedNumber(Number);
}

int main()
{ 

    if (IsPalindromeNumber(ReadPositiveNumber("Please Enter Number : ")))
        cout << "Yes, It is a Palindrome number : " << endl;
    
    else 
        cout << "No, It is Not Palindrome number : " << endl;

    return 0;
}