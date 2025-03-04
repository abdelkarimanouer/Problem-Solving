#include <iostream>
#include <string>

using namespace std;

short ReadYear()
{
    short Year;

    cout << "Enter Year? ";
    cin >> Year;

    return Year;
}

short ReadMonth()
{
    short Month;

    cout << "\nEnter Month? ";
    cin >> Month;

    return Month;
}

short ReadDay()
{
    short Day;

    cout << "\nEnter Day? ";
    cin >> Day;

    return Day;
}

short DayOfWeekOrder(short Year, short Month, short Day)
{
    short a, y, m;

    a = (14 - Month) / 12;
    y = Year - a;
    m = Month + (12*a) - 2;

    return ( Day + y + (y/4) - (y/100) + (y/400) + ((31*m)/12) ) % 7;

}

string DayName(short DayOrder)
{
    string NameDay[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    return NameDay[DayOrder];
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();
    short Day = ReadDay();
    short DayOrder = DayOfWeekOrder(Year, Month, Day);

    cout << "\nDate    : " << Day << "/" << Month << "/" << Year << endl;
    cout << "Day Order : " << DayOrder << endl;
    cout << "Day Name  :" << DayName(DayOrder) << endl;

    system("pause>0");
    return 0;
}
