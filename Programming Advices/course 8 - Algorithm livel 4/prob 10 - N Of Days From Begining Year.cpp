#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

short ReadYear()
{
    short Year;

    cout << "\nEnter Year? ";
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

    cout << "\nEnter Month? ";
    cin >> Month;

    return Month;
}

bool CheckYearIsLeap(short Year)
{
    return (Year % 400 == 0) || ( (Year % 4 == 0) && (Year % 100 != 0) );
}

short NumberDaysInMonth(short Year, short Month)
{
    if(Month < 1 || Month > 12)
    {
        return 0;
    }

    short NumberofDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    return (Month == 2) ? (CheckYearIsLeap(Year) ? 29 : 28) : NumberofDays[Month - 1];
}

int NumberOfDaysFromTheBeginigOfYear(short Year, short Month, short Day)
{
    int TotalDays = 0;

    for (int i = 1; i <= Month - 1; i++)
    {
        TotalDays += NumberDaysInMonth(Year, i);
    }
    TotalDays += Day;

    return TotalDays;
}

int main()
{
    short Day = ReadDay();
    short Month = ReadMonth();
    short Year = ReadYear();

    cout << "\nNumber of days from the begining of year is " << NumberOfDaysFromTheBeginigOfYear(Year, Month, Day) << endl;


    cout << endl;
    system("pause>0");
    return 0;
}

