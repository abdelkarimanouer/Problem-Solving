#include <iostream>
#include <string>
using namespace std;

string ReadString()
{
    string S;

    cout << "Please enter your string?" << endl;
    getline(cin, S);

    return S;
}

string UpperFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    for (int i = 0; i < S1.length(); i++) 
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            S1[i] = toupper(S1[i]);   
        }
        
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }
    return S1;
}

int main()
{    
    string S1 = ReadString();

    cout << "\nString after conversion: " << endl;    

    S1 = UpperFirstLetterOfEachWord(S1);
    cout << S1 << endl;

    system("pause>0");
}
