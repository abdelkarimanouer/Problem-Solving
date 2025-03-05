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

stDate StringTostDate(string strDate)
{
    stDate Date;
    vector <string> vDate = SplitString(strDate, "/");

    Date.Day = stoi(vDate[0]);
    Date.Month = stoi(vDate[1]);
    Date.Year = stoi(vDate[2]);

    return Date;
}

string FormateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    
    FormattedDateString = ReplaceWordsInStringUsingBuiltInFunction(DateFormat, "dd", to_string(Date.Day));
    FormattedDateString = ReplaceWordsInStringUsingBuiltInFunction(FormattedDateString, "mm", to_string(Date.Month));
    FormattedDateString = ReplaceWordsInStringUsingBuiltInFunction(FormattedDateString, "yyyy", to_string(Date.Year));

    return FormattedDateString;
}

int main()
{  
    string strDate = ReadDateAsString();
    stDate Date = StringTostDate(strDate);

    cout << FormateDate(Date) << endl;
    cout << FormateDate(Date, "yyyy/mm/dd") << endl;
    cout << FormateDate(Date, "mm/dd/yyyy") << endl;
    cout << FormateDate(Date, "mm-dd-yyyy") << endl;
    cout << FormateDate(Date, "dd-mm-yyyy") << endl;
    cout << FormateDate(Date, "Day:dd, Month:mm, Year:yyyy") << endl;

    cout << endl;
    system("pause>0");
    return 0;
}

