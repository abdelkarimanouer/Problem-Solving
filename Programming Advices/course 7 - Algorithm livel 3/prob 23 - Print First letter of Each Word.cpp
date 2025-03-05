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

void PrintFirstLetterOfEachWord(string S1)
{
    bool isFirstLetter = true;

    cout << "First Letters of this string:" << endl;
    
    for (int i = 0; i < S1.length(); i++) 
    {
        if (S1[i] != ' ' && isFirstLetter)
        {
            cout << S1[i] << endl;
        }
        
        isFirstLetter = (S1[i] == ' ' ? true : false);
    }

}

int main()
{     
    PrintFirstLetterOfEachWord(ReadString());


    system("pause>0");
}
