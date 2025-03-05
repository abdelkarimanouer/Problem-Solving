#include <iostream>
using namespace std;

enum enCompareDate{ Before = -1, Equal = 0, After = 1};

struct sDate
{
    short Year;
    short Month;
    short Day;
};

struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
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

sPeriod ReadPeriod()
{
    sPeriod Period;

    cout << "Enter Start Date: \n";
    Period.StartDate.Day = ReadDay();
    Period.StartDate.Month = ReadMonth();
    Period.StartDate.Year = ReadYear();

    cout << "\nEnter End Date: \n";
    Period.EndDate.Day = ReadDay();
    Period.EndDate.Month = ReadMonth();
    Period.EndDate.Year = ReadYear();

    return Period;
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return ( Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? ( Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false )) : false );
}

bool IsLastDayInMonth(sDate Date)
{
    return ( Date.Day == NumberDaysInMonth(Date.Year, Date.Month) );
}

bool IsLastMonthInYear(short Month)
{
    return (Month == 12);
}

sDate IncreaseDateByOneDay(sDate Date)
{
    if (IsLastDayInMonth(Date))
    {
        if (IsLastMonthInYear(Date.Month))
        {
            Date.Year++;
            Date.Day = 1;
            Date.Month = 1;        
        }
        else
        {
            Date.Month++;
            Date.Day = 1;            
        }  

    }
    else
        Date.Day++;
    
        
    return Date;
}

int DeffrenceBetweenDate1AndDate2(sDate Date1, sDate Date2, bool IncludLastDay = false)
{    
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludLastDay ? ++Days : Days ;
    
}

int PeriodLength(sPeriod Period, bool IncludEndDay = false)
{
    return DeffrenceBetweenDate1AndDate2(Period.StartDate, Period.EndDate, IncludEndDay);
}

int main()
{
    cout << "\nEnter Period 1: \n";
    sPeriod Period1 = ReadPeriod();

    cout << "\nPeriod Length is: " << PeriodLength(Period1) << endl;
    cout << "Period Length (Including end Date) is: " << PeriodLength(Period1, true) << endl;


    cout << endl;
    system("pause>0");
    return 0;
}


