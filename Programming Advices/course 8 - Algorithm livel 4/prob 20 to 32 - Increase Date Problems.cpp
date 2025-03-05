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

sDate IncreaseDateByXDays(sDate Date, short XDays)
{
    for (int i = 1; i <= XDays; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }
    return Date;
}

sDate IncreaseDateByOneWeek(sDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = IncreaseDateByOneDay(Date);
    }

    return Date;
}

sDate IncreaseDateByXWeek(sDate Date, short XWeeks)
{
    for (int i = 1; i <= XWeeks; i++)
    {
        Date = IncreaseDateByOneWeek(Date);
    }

    return Date;
}

sDate IncreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 12)
    {        
        Date.Month = 1;
        Date.Year++;
        
    }
    else
        Date.Month++;

    short NumberOfDays = NumberDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberOfDays)
    {
        Date.Day = NumberOfDays;
    }
    

    return Date;
}

sDate IncreaseDateByXMonth(sDate Date, short XMonths)
{
    for (int i = 1; i <= XMonths; i++)
    {
        Date = IncreaseDateByOneMonth(Date);
    }

    return Date;
}

sDate IncreaseDateByOneYear(sDate Date)
{
    Date.Year++;
    return Date;
}

sDate IncreaseDateByXYear(sDate Date, short XYears)
{
    for (int i = 1; i <= XYears; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }
    
    return Date;
}

sDate IncreaseDateByXYearFaster(sDate Date, short XYears)
{
    Date.Year += XYears;
    return Date;
}

sDate IncreaseDateByOneDecade(sDate Date)
{
    Date.Year += 10;
    return Date;
}

sDate IncreaseDateByXDecade(sDate Date, short XDecade)
{
    for (int i = 1; i <= XDecade * 10; i++)
    {
        Date = IncreaseDateByOneYear(Date);
    }

    return Date;
}

sDate IncreaseDateByXDecadeFaster(sDate Date, short XDecade)
{
    Date.Year += XDecade * 10;
    return Date;
}

sDate IncreaseDateByCentury(sDate Date)
{
    Date.Year += 100;
    return Date;
}

sDate IncreaseDateByMillennium(sDate Date)
{
    Date.Year += 1000;
    return Date;
}


int main()
{
    sDate Date = ReadFullDate();
    
    cout << "\nDate After: \n\n";

    Date = IncreaseDateByOneDay(Date);
    cout << "1 - Date After Adding One Day : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;
    
    Date = IncreaseDateByXDays(Date, 10);
    cout << "2 - Date After Adding 10 Days : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneWeek(Date);
    cout << "3 - Date After Adding One Week : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;    
    
    Date = IncreaseDateByXWeek(Date, 10);
    cout << "4 - Date After Adding 10 Weeks : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneMonth(Date);
    cout << "5 - Date After Adding One Month : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;    

    Date = IncreaseDateByXMonth(Date, 5);
    cout << "6 - Date After Adding 5 Months : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneYear(Date);
    cout << "7 - Date After Adding One Year : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;    
    
    Date = IncreaseDateByXYear(Date, 10);
    cout << "8 - Date After Adding 10 Years : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXYearFaster(Date, 10);
    cout << "9 - Date After Adding 10 Years (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByOneDecade(Date);
    cout << "10 - Date After Adding One Decade : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 

    Date = IncreaseDateByXDecade(Date, 10);
    cout << "11 - Date After Adding 10 Decades : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByXDecadeFaster(Date, 10);
    cout << "12 - Date After Adding 10 Decades (Faster) : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByCentury(Date);
    cout << "13 - Date After Adding One Century : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = IncreaseDateByMillennium(Date);
    cout << "14 - Date After Adding One Millennium : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;    



    cout << endl;
    system("pause>0");
    return 0;
}

