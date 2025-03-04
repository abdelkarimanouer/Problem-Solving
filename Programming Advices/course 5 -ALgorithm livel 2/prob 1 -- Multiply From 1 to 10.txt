#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void PrintTableHeader()
{
    cout << "\n\t\t\t Multiplication Table From 1 To 10\n\n";
    cout << "\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n_____________________________________________________________________________________________\n";
    
}

string ColumSperator(int i)
{
    if (i < 10)
    
        return "   |";
    else
        return "  |";
}

void PrintMultiplicationtable()
{
    PrintTableHeader();

    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << ColumSperator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
    
}

int main()
{  
    PrintMultiplicationtable();


    return 0;
}
