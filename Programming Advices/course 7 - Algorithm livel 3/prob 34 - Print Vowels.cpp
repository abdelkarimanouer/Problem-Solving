#include <string> 
#include<iostream> 
using namespace std; 

string ReadString()
{
    string S1;

    cout << "Please enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

bool IsVowel(char Letter)
{
    Letter = tolower(Letter);

    return (Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u');
}

void PrintVowels(string S1)
{
    cout << "\nVowels in string are: ";

    for(short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            cout << S1[i] << "   ";
    }

    cout << endl;
}

int main()
{
    string S1 = ReadString();

    PrintVowels(S1);


    system("pause>0");
}
