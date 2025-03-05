#pragma warning(disable : 4996)
#include <iostream>
#include <ctime>

using namespace std;

struct sDate
{
    short Year;
    short Month;
    short Day;
};

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

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12*a) - 2;

    return ( Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12) ) % 7;

}

short DayOfWeekOrder(sDate Date)
{
    return DayOfWeekOrder(Date.Year, Date.Month, Date.Day);
}

string DayName(short DayOrder)
{
    string NameDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    return NameDay[DayOrder];
}

sDate GetSystemDate(sDate Date)
{
    time_t t = time(0); // get time now
    tm* now = localtime(&t); 
       
    Date.Day = now->tm_mday;
    Date.Month = now->tm_mon + 1;
    Date.Year = now->tm_year + 1900;

    return Date;
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

bool IsTheEndOfWeek(sDate Date)
{
    return DayOfWeekOrder(Date) == 6;
}

bool IsTheWeekend(sDate Date)
{
    return ( DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 0 ) ;
}

bool IsBusinessDay(sDate Date)
{
    return !IsTheWeekend(Date);
}

short DaysUntilEndOfWeek(sDate Date)
{
    return 6 - DayOfWeekOrder(Date);
}

short DaysUntilEndOfMonth(sDate Date)
{
    sDate EndMonthDay;

    EndMonthDay.Day = NumberDaysInMonth(Date.Year, Date.Month);
    EndMonthDay.Month = Date.Month;
    EndMonthDay.Year = Date.Year;

    return DeffrenceBetweenDate1AndDate2(Date, EndMonthDay);
}

short DaysUntilEndOfYear(sDate Date)
{
    sDate EndYearDays;

    EndYearDays.Day = 31;
    EndYearDays.Month = 12;
    EndYearDays.Year = Date.Year;

    return DeffrenceBetweenDate1AndDate2(Date, EndYearDays);
}

int main()
{
    sDate Date = GetSystemDate(Date);

    cout << "\nToday is " << DayName(DayOfWeekOrder(Date)) << ", " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 
//-------------------------------------------------------------------------------------
    cout << "\nIs it the end of Week? " << endl;
    if (IsTheEndOfWeek(Date))
        cout << "Yes, Saturday is end of Week." << endl;
    else
        cout << "No, it is Not end of Week." << endl;
//-------------------------------------------------------------------------------------
    cout << "\nIs it the Weekend? " << endl;
    if (IsTheWeekend(Date))
        cout << "Yes, " << DayName(DayOfWeekOrder(Date)) << " is Weekend." << endl;
    else
        cout << "No, it is Not Weekend." << endl;
//-------------------------------------------------------------------------------------
    cout << "\nIs it the Business Day? " << endl;
    if (IsBusinessDay(Date))
        cout << "Yes, it is Business Day." << endl;
    else
        cout << "No, it is Not Business Day." << endl;
//-------------------------------------------------------------------------------------
    cout << "\nDays Until End of Week is : " << DaysUntilEndOfWeek(Date) << " Day(s).\n";
    cout << "Days Until End of Month is : " << DaysUntilEndOfMonth(Date) << " Day(s).\n";
    cout << "Days Until End of Year is : " << DaysUntilEndOfYear(Date) << " Day(s).\n";



    cout << endl;
    system("pause>0");
    return 0;
}
