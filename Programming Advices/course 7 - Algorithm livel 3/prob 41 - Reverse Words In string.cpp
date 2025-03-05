#include <iostream>
#include <string>
#include <vector>
using namespace std;

string ReadString()
{
    string S1;

    cout << "Please enter Your String?" << endl;
    getline(cin, S1);

    return S1;
}

vector <string> SplitString(string S1, string delime)
{
    vector <string> vSplit;

    short pos = 0;
    string sWord;

    while((pos = S1.find(delime)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vSplit.push_back(sWord);
        }

        S1.erase(0, pos + delime.length());
    }
    
    if(S1 != "")
    {
        vSplit.push_back(S1);
    }

    return vSplit;
}

string ReverseWordsInstring(string S1)
{
    vector <string> vString;
    string S2 = "";

    vString = SplitString(S1, " ");

    vector <string>::iterator iter = vString.end();

    while(iter != vString.begin())
    {
        iter--;

        S2 += *iter + " ";        
    }


    return S2.substr(0, S2.length() - 1);
}

int main()
{
    string S1 = ReadString();

    cout << "\nString after reversing words: " << endl;
    cout << ReverseWordsInstring(S1) << endl;


    system("pause>0");
}
