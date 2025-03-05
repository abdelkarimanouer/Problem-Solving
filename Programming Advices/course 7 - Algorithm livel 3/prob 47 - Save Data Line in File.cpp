#include <iostream>
#include <fstream>
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

stClient ReadClientData()
{
    stClient Client;

    cout << "\nEnter Account Number? ";
// Ussage of std::ws will extrat all the withespace character
    getline(cin >> ws, Client.AccountNumber);

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

void AddDataLineToFile(string FileName , string stDataLine)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out | ios::app);

    if (MyFile.is_open())
    {
        MyFile << stDataLine << endl;

        MyFile.close();
    }
    
}

void AddNewClient()
{
    stClient Client;
    Client = ReadClientData();
    AddDataLineToFile(ClientsFile , ConvertRecordToLine(Client));
}

void AddClients()
{
    char AddMore = 'Y';
 
    do
    {
        system("cls");

        cout << "Adding New Client: " << endl;

        AddNewClient();

        cout << "Client Added Successfully, Do you want add more clients? ";
        cin >> AddMore;

    } while (toupper(AddMore) == 'Y');
    

}

int main()
{    
    AddClients();


    system("pause>0");

    
}

