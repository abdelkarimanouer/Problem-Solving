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
    int AccountBalance;
};

stClient ReadClientData()
{
    stClient Client;

    cout << "\nEnter Account Number? ";
    getline(cin, Client.AccountNumber);

    cout << "Enter PinCode? ";
    getline(cin, Client.PinCode);

    cout << "Enter Name? ";
    getline(cin, Client.Name);

    cout << "Enter Phone? ";
    getline(cin, Client.Phone);

    cout << "Enter AccountBalance? ";
    cin >> Client.AccountBalance;

    return Client;
}

string ConvertRecordToLine(stClient Client, string Seperator = "#//#")
{
    string strClientRecord = "";

    strClientRecord += Client.AccountNumber + Seperator;
    strClientRecord += Client.PinCode + Seperator;
    strClientRecord += Client.Name + Seperator;
    strClientRecord += Client.Phone + Seperator;
    strClientRecord += to_string(Client.AccountBalance);

    return strClientRecord;
}

int main()
{
    cout << "\nPlease Enter Client Client: " << endl;

    stClient Client;
    Client = ReadClientData();
    
    cout << "\n\nClient Record for saving is: " << endl;
    cout << ConvertRecordToLine(Client) << endl;

    system("pause>0");

    
}

