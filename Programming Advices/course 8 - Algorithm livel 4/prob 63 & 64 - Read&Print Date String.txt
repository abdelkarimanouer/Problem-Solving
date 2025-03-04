#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

string ReadDateAsString()
{
    string Date;

    cout << "\nPlease enter date dd/mm/yyyy : ";
    cin >> Date;

    return Date;
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

stDate StringTostDate(string strDate)
{
    stDate Date;
    vector <string> vDate = SplitString(strDate, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string DatetoString(stDate Date)
{
    string strDate = to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);

    return strDate;
}

int main()
{  
    string strDate = ReadDateAsString();
    stDate Date = StringTostDate(strDate);

    cout << "\nDay: " << Date.Day << endl;
    cout << "Month: " << Date.Month << endl;
    cout << "Year: " << Date.Year << endl;

    cout << "\nYou Entered: " << DatetoString(Date) << endl;



    cout << endl;
    system("pause>0");
    return 0;
}

