#include <iostream>
#include <string>
#include <vector>
using namespace std;

string JoinString(vector<string> &vString, string Delime)
{
    string S1 = "";

    for (string &i : vString)
    {
        S1 = S1 + i + Delime;
    }

    return S1.substr(0, S1.length() - Delime.length());
}

int main()
{
    vector<string> vString = {"Abdelkarim", "Anouer", "Ismail", "Adam"};

    cout << "Vector after join: " << endl;
    cout << JoinString(vString, "") << endl;

    system("pause>0");
}