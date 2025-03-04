#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

string JoinString(vector<string> &vString, string Delime)
{
    string S1 = "";

    for (string &i : vString)
    {
        S1 = S1 + i + Delime;
    }

    return S1.substr(0, S1.length() - Delime.length());
}

string LowerAllString(string S1)
{
    for (int i = 0; i < S1.length(); i++)
    {
        S1[i] = tolower(S1[i]);
    }
    return S1;
}

string ReplaceWordInStringUsingSplit(string S1, string StringWantReplace, string sToReplace, bool MatchCase = true)
{   
    vector<string> vString = SplitString(S1, " ");
    
    for (string& s : vString)
    {
        if(MatchCase)
        {
            if (s == StringWantReplace)
            {
                s = sToReplace;
            }
        }
        else
        {
            if (LowerAllString(s) == LowerAllString(StringWantReplace))
            {
                s = sToReplace;
            }
        }       
    }
    return JoinString(vString, " ");
}


int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringWantReplace = "jordan";
    string sToReplace = "USA";

    cout << "\nOriginal String: \n" << S1;

    cout << "\n\nReplace with match case: \n";
    cout << ReplaceWordInStringUsingSplit(S1, StringWantReplace, sToReplace) << endl;

    cout << "\nReplace with dont match case: " << endl;
    cout << ReplaceWordInStringUsingSplit(S1, StringWantReplace, sToReplace, false) << endl;


    system("pause>0");
}

