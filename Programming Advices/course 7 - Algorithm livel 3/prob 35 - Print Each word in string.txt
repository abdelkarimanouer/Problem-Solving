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

void PrintEachWord(string S1)
{
    string delime = " ";

    cout << "\nYour string words are: \n\n";
    short pos = 0;
    string sWord;

    while((pos = S1.find(delime)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            cout << sWord << endl;
        }

        S1.erase(0, pos + delime.length());
    }
    
    if(S1 != "")
    {
        cout << S1 << endl;
    }

}

int main()
{

    PrintEachWord(ReadString());


    system("pause>0");
}
