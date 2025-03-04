#include <iostream>
#include <string>
#include <cmath>
using namespace std;

float ReadNumber()
{
    float Number = 0;

    cout << "\nPlease enter Number : ";
    cin >> Number;

    return Number;   
}

int MySqrt(float Number)
{   
    return pow(Number, 0.5);
}

int main()
{

    float Number = ReadNumber();

    cout << "My Sqrt Result : " << MySqrt(Number) << endl;
    
    cout << "C++ Sqrt Result : " << sqrt(Number) << endl;

    cout << endl;

    return 0;
}

