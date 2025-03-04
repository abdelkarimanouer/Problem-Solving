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

    cout << "Enter Day? ";
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

bool IsTheWeekend(sDate Date)
{
    return (DayOfWeekOrder(Date) == 6 || DayOfWeekOrder(Date) == 0) ;
}

bool IsBusinessDay(sDate Date)
{
    return !IsTheWeekend(Date);
}

short CalculateVacationDays(sDate DateFrom, sDate DateTo)
{
    short VacationDays = 0;
        
    while (IsDate1BeforeDate2(DateFrom, DateTo))
    {
        if (IsBusinessDay(DateFrom))
            VacationDays++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return VacationDays;
}

int main()
{
    cout << "\nVacation Starts: \n";
    sDate DateFrom = ReadFullDate();
    
    cout << "\nVacation End: \n";
    sDate DateTo = ReadFullDate();
   
    cout << "\nVacation From : " << DayName(DayOfWeekOrder(DateFrom)) << ", " << DateFrom.Day << "/" << DateFrom.Month << "/" << DateFrom.Year << endl;
    cout << "\nVacation To : " << DayName(DayOfWeekOrder(DateTo)) << ", " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;

    cout << "\nActucal Vacation Days is: " << CalculateVacationDays(DateFrom, DateTo) << endl; 


    cout << endl;
    system("pause>0");
    return 0;
}
