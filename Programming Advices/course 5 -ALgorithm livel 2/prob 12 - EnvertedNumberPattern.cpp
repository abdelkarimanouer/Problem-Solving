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

void invertedpattern(int Number)
{
    for (int i = Number; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << i;
        }
        cout << endl;
    }
    
}

int main()
{ 
    invertedpattern(ReadPositiveNumber("Please enter Number : "));


    return 0;
}