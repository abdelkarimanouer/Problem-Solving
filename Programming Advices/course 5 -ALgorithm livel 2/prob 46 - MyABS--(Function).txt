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

float MyABS(float Number)
{    
    if (Number > 0)
        return Number; 
    else
        return Number * -1;
}

int main()
{

    float Number = ReadNumber();

    cout << "My abs Result : " << MyABS(Number) << endl;
    
    cout << "C++ abs Result : " << abs(Number) << endl;

    cout << endl;

    return 0;
}

