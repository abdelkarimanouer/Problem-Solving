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

int main()
{
    sDate Date = ReadFullDate();
    
    Date = IncreaseDateByOneDay(Date);

    cout << "Date After Adding One Day : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;


    cout << endl;
    system("pause>0");
    return 0;
}

