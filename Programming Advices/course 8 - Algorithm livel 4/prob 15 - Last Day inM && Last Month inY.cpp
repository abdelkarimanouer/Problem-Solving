#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
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

bool IsLastDayInMonth(sDate Date)
{
    return ( Date.Day == NumberDaysInMonth(Date.Year, Date.Month) );
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

int main()
{
    sDate Date = ReadFullDate();
    
    if (IsLastDayInMonth(Date))
        cout << "\nYes, Day Is last day in Month." << endl;
    else
        cout << "\nNo, Day Is Not Last day in Month.\n";


    if (IsLastMonthInYear(Date.Month))
        cout << "\nYes, Month Is last Month in Year." << endl;
    else
        cout << "\nNo, Month Is Not last Month in Year.\n";
    


    cout << endl;
    system("pause>0");
    return 0;
}

