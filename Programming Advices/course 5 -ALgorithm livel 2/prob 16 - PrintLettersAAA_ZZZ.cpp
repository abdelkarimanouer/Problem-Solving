#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void PrintLetterFromAAA_TO_ZZZ()
{
    cout << endl;
    string Word = "";
    for (int i = 65; i <= 90 ; i++)
    {
        for (int j = 65 ; j <= 90; j++)
        {
            for (int k = 65; k <= 90; k++)
            {
                Word = Word + char(i);
                Word = Word + char(j);
                Word = Word + char(k);

                cout << Word << endl;

                Word = "";
            } 
        }   
    }
}
int main()
{ 
    PrintLetterFromAAA_TO_ZZZ();


    return 0;
}

