#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

const string ClientsFile = "Clients.txt";

struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    int AccountBalance;
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

vector <stClient> LoadClientsDataFromFile(string FileName)
{
    vector <stClient> vClients;

    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if(MyFile.is_open())
    {
        string Line;
        stClient Client;

        while (getline(MyFile, Line))
        {
            Client = ConvertLineRecord(Line);

            vClients.push_back(Client);
        }
        MyFile.close();
    }

    return vClients;
}

void PrintClientCard(stClient &Client)
{
    cout << "\nThe following is the Client details: \n\n";    
    cout << "Account Number : " << Client.AccountNumber << endl;
    cout << "Pin Code       : " << Client.PinCode << endl;
    cout << "Name           : " << Client.Name << endl;
    cout << "Phone          : " << Client.Phone << endl;
    cout << "Acount Balance : " << Client.AccountBalance << endl;
}

bool FindClientByAccountNumber(stClient &Client ,string AcNumber)
{   
    vector <stClient> vClients = LoadClientsDataFromFile(ClientsFile);

    for (stClient C : vClients)
    {
        if (C.AccountNumber == AcNumber)
        {
            Client = C;
            return true;
        }
    }
    return false;
}

string ReadAccountnumber()
{
    string AcNumber;

    cout << "Please enter AccountNumber ? ";
    cin >> AcNumber ;

    return AcNumber;
}


int main()
{    
    stClient Client;
    string AcNumber = ReadAccountnumber();

    if (FindClientByAccountNumber(Client, AcNumber))
    {
        PrintClientCard(Client);
    }
    else
        cout << "\nClient with Account Number (" << AcNumber << ") NOT found \n";
      


    system("pause>0");

}
