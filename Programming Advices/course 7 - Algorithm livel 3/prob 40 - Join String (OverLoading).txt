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

string JoinString(string arrString[], short Length , string Delime)
{
    string S1 = "";

    for (short i = 0; i < Length ; i++)
    {
        S1 = S1 + arrString[i] + Delime;
    }

    return S1.substr(0, S1.length() - Delime.length());
}

int main()
{
    vector<string> vString = {"Abdelkarim", "Anouer", "Ismail", "Adam"};
    string arrString[] = {"Abdelkarim", "Anouer", "Ismail", "Adam"};

    cout << "\nVector after join: " << endl;
    cout << JoinString(vString, " ") << endl;

    cout << "\nArray after join: " << endl;
    cout << JoinString(arrString, 4, " ") << endl;

    system("pause>0");
}