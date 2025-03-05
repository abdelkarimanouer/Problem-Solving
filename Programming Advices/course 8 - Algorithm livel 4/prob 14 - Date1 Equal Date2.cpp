#include <iostream>
using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year;

    cout << "Enter Year? ";
    cin >> Year;

    return Year;
}

short ReadDay()
{
    short Day;

    cout << "\nEnter Day? ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month;

    cout << "Enter Month? ";
    cin >> Month;

    return Month;
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();

    return Date;
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
}


int main()
{
    sDate Date1 = ReadFullDate();
    sDate Date2 = ReadFullDate();
    
    if (IsDate1EqualDate2(Date1, Date2))
    {
        cout << "\nYes, Date1 is Equal Date2." << endl;
    }
    else
        cout << "\nNo, Date1 is Not Equal Date2." << endl;



    cout << endl;
    system("pause>0");
    return 0;
}

