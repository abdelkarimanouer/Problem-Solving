#include <iostream>
using namespace std;

enum enCompareDate{ Before = -1, Equal = 0, After = 1};

struct sDate
{
    short Year;
    short Month;
    short Day;
};

short ReadYear()
{
    short Year;

    cout << "=> Enter Year? ";
    cin >> Year;

    return Year;
}

short ReadDay()
{
    short Day;

    cout << "\n=> Enter Day? ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month;

    cout << "=> Enter Month? ";
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return ( Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? ( Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false )) : false );
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return ( !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2) ) ;
}

enCompareDate CompareDateResult(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;
    else if(IsDate1EqualDate2(Date1, Date2))
        return enCompareDate::Equal;

    return enCompareDate::After;
}


int main()
{
    cout << "\nEnter Date1: \n";
    sDate Date1 = ReadFullDate();

    cout << "\nEnter Date2: \n";
    sDate Date2 = ReadFullDate();

    cout << "\nCompare Result = " << CompareDateResult(Date1, Date2) << endl;


    cout << endl;
    system("pause>0");
    return 0;
}

