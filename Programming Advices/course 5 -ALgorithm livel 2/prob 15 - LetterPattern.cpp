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

void PatternLetter(int Number)
{
    cout << endl;
    for (int i = 65; i <= 65 + Number - 1 ; i++)
    {
        for (int j = 1; j <= i - 65 + 1; j++)
        {
            cout << char(i);
        }
        cout << endl;
    }
}

int main()
{ 
    PatternLetter(ReadPositiveNumber("Please Enter Positive Number : "));


    return 0;
}