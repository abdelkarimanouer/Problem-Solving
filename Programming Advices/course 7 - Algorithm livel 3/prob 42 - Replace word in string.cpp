#include <iostream>
#include <string>
using namespace std;

string ReplaceWordsInStringUsingBuiltInFunction(string S1, string StringWantReplace, string sToReplace)
{
    short pos = S1.find(StringWantReplace);

    while (pos != std::string::npos)
    {
        S1.replace(pos, StringWantReplace.length(), sToReplace);
        pos = S1.find(StringWantReplace);
    }

    return S1;
}


int main()
{
    string S1 = "Welcome to Jordan , Jordan is a nice country";
    string StringWantReplace = "Jordan";
    string sToReplace = "USA";

    cout << "\nOriginal String: \n" << S1;
    cout << "\n\nString After Replace: \n";
    cout << ReplaceWordsInStringUsingBuiltInFunction(S1, StringWantReplace, sToReplace ) << endl;


    system("pause>0");
}

