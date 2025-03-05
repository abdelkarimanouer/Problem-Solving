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

float GetFractionPart(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{   
    
    int IntPart;
    IntPart = int(Number);

    float FractionPart = GetFractionPart(Number) ;

    if(abs(FractionPart) >= .5)
    {
        if (Number > 0)
            return ++IntPart;
        else 
            return --IntPart;    

    }
    else
        return IntPart;
}

int main()
{

    float Number = ReadNumber();

    cout << "My Round Result : " << MyRound(Number) << endl;
    
    cout << "C++ round Result : " << round(Number) << endl;

    cout << endl;

    return 0;
}

