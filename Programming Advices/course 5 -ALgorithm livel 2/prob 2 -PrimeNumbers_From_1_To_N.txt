#include <iostream>
#include <cmath>
#include <string>
using namespace std;

enum enPrimeNotPrime {Prime = 1 , NotPrime = 2};

float ReadPositiveNumber(string msg)
{
    float Number = 0;
    do
    {
        cout << msg << endl;
        cin >> Number;
    } while (Number <= 0);
    
    return Number; 
}

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
        
    }
    return enPrimeNotPrime::Prime;

}

void PrintPrime1ToN(int Number)
{
    cout << "\n";
    cout << "The Prime Numbers From " << 1 << " To " << Number << " are :" <<endl;
    for (int i = 1; i <= Number; i++)
    {
        if (CheckPrime(i) == enPrimeNotPrime::Prime)
        {
            cout << i << endl;
        }  
    }
}

int main()
{
    PrintPrime1ToN(ReadPositiveNumber("Please Enter Number : "));
    

    return 0;
}