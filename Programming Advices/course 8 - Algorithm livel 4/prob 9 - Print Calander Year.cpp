#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

short ReadYear()
{
    short Year;

    cout << "Enter Year? ";
    cin >> Year;

    return Year;
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

string NameMonth(short Month)
{
    string NameMonth[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    return NameMonth[Month - 1];
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12*a) - 2;

    return ( Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12) ) % 7;

}

void PrintMonthCalander(short Year, short Month)
{
    int current = DayOfWeekOrder(Year, Month, 1);

    int NumberOfDays = NumberDaysInMonth(Year, Month);

    printf("\n_________________%s_________________\n", NameMonth(Month).c_str());

    printf("\n  Sun  Mon  Tue  Wen  Thu  Fri  Sat\n");
    
    int i;
    for (i = 0; i < current; i++)
        printf("     ");
    
    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d", j);

        if (++i == 7)
        {
            i = 0;
            cout << "\n";
        }
    }
}

void PrintYearCalander(short Year)
{
    printf("\n--------------------------------------\n");
    printf("           Calander - %d\n", Year);
    printf("--------------------------------------\n");

    for (int i = 1; i <= 12; i++)
    {
        PrintMonthCalander(Year,i);
    }
    
}

int main()
{
    short Year = ReadYear();

    PrintYearCalander(Year);

    cout << endl;
    system("pause>0");
    return 0;
}

