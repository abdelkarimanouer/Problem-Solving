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

short CountVowels(string S1)
{
    short count = 0;

    for(short i = 0; i < S1.length(); i++)
    {
        if (IsVowel(S1[i]))
            count++;
        
    }
    return count;
}

int main()
{
    string S1 = ReadString();

    cout << "\nNumber of Vowels is: " << CountVowels(S1) << endl;

    system("pause>0");
}
