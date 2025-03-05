#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S1;

    cout << "Please enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

char InvertLetterCase(char Char1)
{
    return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

string InvertingAllLettersCase(string S1)
{
    for(int i = 0; i < S1.length(); i++)
    {
        S1[i] = InvertLetterCase(S1[i]);
    }
    return S1;
}

int main()
{
    string S1 = ReadString();
    
    cout << "\nString After inverting All Letters Case: " << endl;
    S1 = InvertingAllLettersCase(S1);
    cout << S1 << endl; 


    system("pause>0");
}
