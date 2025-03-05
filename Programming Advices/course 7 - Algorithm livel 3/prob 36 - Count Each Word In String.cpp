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

short CountEachWord(string S1)
{
    short counter = 0;

    string delime = " ";
    short pos = 0;
    string sWord;

    while((pos = S1.find(delime)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            counter++;
        }

        S1.erase(0, pos + delime.length());
    }
    
    if(S1 != "")
    {
        counter++;
    }

    return counter;
}

int main()
{
    string S1 = ReadString();

    cout << "\nThe number of words in your string is: " << CountEachWord(S1) << endl;


    system("pause>0");
}
