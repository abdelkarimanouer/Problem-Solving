#include <string> 
#include<iostream> 
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

int main()
{
    vector <string> vSplit;

    string S1 = ReadString();
    vSplit = SplitString(S1, " ");

    cout << "\nTokens = " << vSplit.size() << endl;
    for (string& i : vSplit)
    {
        cout << i << endl;
    }
    

    system("pause>0");
}
