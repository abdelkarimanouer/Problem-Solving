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

    if(Month == 2)
    {
        return CheckYearIsLeap(Year) ? 29 : 28;
    }

    short arr31Days[7] = {1,3,5,7,8,10,12};

    for(short i = 1; i <= 12 ; i++)
    {
        if(arr31Days[i - 1] == Month)
        {
            return 31;
        }
    }

    return 30;
}

short NumberHoursInMonth(short Year, short Month)
{
    return NumberDaysInMonth(Year, Month) * 24;
}

int NumberMinutesInMonth(short Year, short Month)
{
    return NumberHoursInMonth(Year, Month) * 60;
}

int NumberSecondsInMonth(short Year, short Month)
{
    return NumberMinutesInMonth(Year, Month) * 60;
}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();


    cout << "\nNumber Of Days    In Month [" << Year << "] is " << NumberDaysInMonth(Year, Month) << endl;
    cout << "Number Of Hours   In Month [" << Year << "] is " << NumberHoursInMonth(Year, Month) << endl;
    cout << "Number Of Minutes In Month [" << Year << "] is " << NumberMinutesInMonth(Year, Month) << endl;
    cout << "Number Of Seconds In Month [" << Year << "] is " << NumberSecondsInMonth(Year, Month) << endl;


    system("pause>0");
    return 0;
}
