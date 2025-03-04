#include <string> 
#include<iostream> 
using namespace std; 

string  ReadString() 
{ 
    string S1;     
    cout << "\nPlease Enter Your String?\n";     
    getline(cin, S1); 
    return S1; 
} 

char ReadChar()
{
    char Char1;

    cout << "\nPlease enter a Character?" << endl;
    cin >> Char1;

    return Char1;
}

char InvertLetterCase(char Char1)
{
    return isupper(Char1) ? tolower(Char1) : toupper(Char1);
}

short CountLetter(string S1, char Letter, bool MatchCase = true)
{
    short count = 0;

    for(short i = 0; i < S1.length(); i++)
    {
        if(MatchCase)
        {
            if (S1[i] == Letter)
            {
                count++;
            }            
        }
        else
        {
            if (tolower(S1[i]) == tolower(Letter))
            {
                count++;
            }
            
        }
    }

    return count;
}


int main()
{
    string S1 = ReadString();
    char Letter = ReadChar();

    cout << "Letter '" << Letter << "' Count = " << CountLetter(S1, Letter) << endl;
    cout << "Letter '" << Letter << "' Or '" << InvertLetterCase(Letter) << "' Count = " << CountLetter(S1, Letter, false) << endl;


    system("pause>0");
}
