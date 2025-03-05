#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
};

vector<string> SplitString(string S1, string delime)
{
    vector <string> vSplit;

    short pos = 0;
    string sWord;

    while ((pos = S1.find(delime)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vSplit.push_back(sWord);
        }

        S1.erase(0, pos + delime.length());
    }

    if (S1 != "")
    {
        vSplit.push_back(S1);
    }

    return vSplit;
}

stClient ConvertLineRecord(string Line, string Seperator = "#//#")
{
    stClient Client;

    vector <string> vSplit;
    vSplit = SplitString(Line, Seperator);

    Client.AccountNumber = vSplit[0];
    Client.PinCode = vSplit[1];
    Client.Name = vSplit[2];
    Client.Phone = vSplit[3];
    Client.AccountBalance = stod(vSplit[4]);

    return Client;
}

void PrintClientRecord(stClient &Client)
{
    cout << "\nThe following is the extracted client record: \n\n";    
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Acount Balance : " << Client.AccountBalance << endl;
}

int main()
{
    stClient Client;
    string stLine = "A150#//#1234#//#Mohammed AbuHadhoud#//#06545452#//#7000";

    cout << "\nLine Record is: \n";
    cout << stLine << endl;

    Client = ConvertLineRecord(stLine, "#//#");
    PrintClientRecord(Client);


    system("pause>0");
}

