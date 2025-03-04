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

sDate CalculateVacationReturnDate(sDate DateFrom, short VacationDays)
{
    short WeekEndCounter = 0;

    //in case the data  is weekend keep adding one day util you reach business day
    //we get rid of all weekends before the first business day
    while (IsTheWeekend(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    //here we increase the vacation dates to add all weekends to it.
    
    for (short i = 1; i <= VacationDays+ WeekEndCounter; i++)
    {

        if (IsTheWeekend(DateFrom))
            WeekEndCounter++;

        DateFrom = IncreaseDateByOneDay(DateFrom);
    }
    
    //in case the return date is week end keep adding one day util you reach business day
    while (IsTheWeekend(DateFrom))
    {
        DateFrom = IncreaseDateByOneDay(DateFrom);
    }

    return DateFrom;
}

short ReadVecationDays()
{
    short VacationDays;

    cout << "\nPlease enter Vacation Days? ";
    cin >> VacationDays;

    return VacationDays;
}

int main()
{
    cout << "\nVacation Starts: \n";
    sDate DateFrom = ReadFullDate();
    short VacationDays = ReadVecationDays();

    sDate DateTo = CalculateVacationReturnDate(DateFrom, VacationDays);

    cout << "\nReturn Date: " << DayName(DayOfWeekOrder(DateTo)) << ", " << DateTo.Day << "/" << DateTo.Month << "/" << DateTo.Year << endl;


    cout << endl;
    system("pause>0");
    return 0;
}
