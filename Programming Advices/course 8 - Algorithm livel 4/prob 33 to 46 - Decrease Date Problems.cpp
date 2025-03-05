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

sDate DecreaseDateByOneDay(sDate Date)
{
    if (Date.Day == 1)
    {
        if (Date.Month == 1)
        {
            Date.Year--;
            Date.Day = 31;
            Date.Month = 12;        
        }
        else
        {
            Date.Month--;
            Date.Day = NumberDaysInMonth(Date.Year, Date.Month);            
        }  

    }
    else
        Date.Day--;
    
        
    return Date;
}

sDate DecreaseDateByXDays(sDate Date , short XDays)
{
    for (int i = 1; i <= XDays; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;
}

sDate DecreaseDateByOneWeek(sDate Date)
{
    for (int i = 1; i <= 7; i++)
    {
        Date = DecreaseDateByOneDay(Date);
    }
    return Date;   
}

sDate DecreaseDateByXWeek(sDate Date, short XWeek)
{
    for (int i = 1; i <= XWeek; i++)
    {
        Date = DecreaseDateByOneWeek(Date);
    }
    return Date;
}

sDate DecreaseDateByOneMonth(sDate Date)
{
    if (Date.Month == 1)
    {
        Date.Year--;
        Date.Month = 12;
        Date.Day = 31;
    }
    else
        Date.Month--;


    short NumberDays = NumberDaysInMonth(Date.Year, Date.Month);
    if (Date.Day > NumberDays)
        Date.Day = NumberDays;

    return Date;
}

sDate DecreaseDateByXMonth(sDate Date, short XMonths)
{
    for (int i = 1; i <= XMonths; i++)
    {
        Date = DecreaseDateByOneMonth(Date);
    }
    return Date;
}

sDate DecreaseDateByOneYear(sDate Date)
{
    Date.Year--;
    return Date;
}

sDate DecreaseDateByXYear(sDate Date, short XYears)
{
    for (int i = 1; i <= XYears; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXYearFaster(sDate Date, short XYears)
{
    Date.Year -= XYears;
    return Date;
}

sDate DecreaseDateByOneDecade(sDate Date)
{
    Date.Year -= 10;
    return Date;
}

sDate DecreaseDateByXDecades(sDate Date, short XDecades)
{
    for (int i = 1; i <= XDecades * 10; i++)
    {
        Date = DecreaseDateByOneYear(Date);
    }
    return Date;
}

sDate DecreaseDateByXDecadesFaster(sDate Date, short XDecades)
{
    Date.Year -= XDecades * 10;
    return Date;
}

sDate DecreaseDateByCentury(sDate Date)
{
    Date.Year -= 100;
    return Date;
}

sDate DecreaseDateByMillennium(sDate Date)
{
    Date.Year -= 1000;
    return Date;
}

int main()
{
    sDate Date = ReadFullDate();
    cout << "\nDate After: \n\n";  

    Date = DecreaseDateByOneDay(Date);
    cout << "1 - Subtracting Date By One Day is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXDays(Date, 10);
    cout << "2 - Subtracting Date By 10 Days is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneWeek(Date);
    cout << "3 - Subtracting Date By One Week is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXWeek(Date, 10);
    cout << "4 - Subtracting Date By 10 Weeks is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneMonth(Date);
    cout << "5 - Subtracting Date By One Month is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXMonth(Date, 5);
    cout << "6 - Subtracting Date By 5 Months is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByOneYear(Date);
    cout << "7 - Subtracting Date By One Year is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYear(Date, 10);
    cout << "8 - Subtracting Date By 10 Years is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;

    Date = DecreaseDateByXYearFaster(Date, 10);
    cout << "9 - Subtracting Date By 10 Years (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl;   

    Date = DecreaseDateByOneDecade(Date);
    cout << "10 - Subtracting Date By One Decade is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 

    Date = DecreaseDateByXDecades(Date, 10);
    cout << "11 - Subtracting Date By 10 Decades is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 

    Date = DecreaseDateByXDecadesFaster(Date, 10);
    cout << "12 - Subtracting Date By 10 Decades (Faster) is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 

    Date = DecreaseDateByCentury(Date);
    cout << "13 - Subtracting Date By One Century is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 

    Date = DecreaseDateByMillennium(Date);
    cout << "14 - Subtracting Date By One Millennium is : " << Date.Day << "/" << Date.Month << "/" << Date.Year << endl; 


    cout << endl;
    system("pause>0");
    return 0;
}

