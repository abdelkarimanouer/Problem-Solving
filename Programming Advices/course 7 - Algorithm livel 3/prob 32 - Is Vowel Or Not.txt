#include <string> 
#include<iostream> 
using namespace std; 

char ReadChar()
{
    char Char1;

    cout << "\nPlease enter a Character?" << endl;
    cin >> Char1;

    return Char1;
}

bool IsVowel(char Letter)
{
    Letter = tolower(Letter);

    return (Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u');
}

int main()
{

    char Letter = ReadChar();

    if (IsVowel(Letter))
        cout << "Yes Letter '" << Letter << "' is vowel" << endl;
    
    else
        cout << "No Letter '" << Letter << "' is NOT vowel" << endl;
    

    system("pause>0");
}
