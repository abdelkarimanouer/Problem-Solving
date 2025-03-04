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

bool CheckYearIsLeap(short Year)
{
    return (Year % 400 == 0) || ( (Year % 4 == 0) && (Year % 100 != 0) );
}

short NumberDaysInYear(short Year)
{
    return CheckYearIsLeap(Year)? 366 : 365;
}

short NumberHoursInYear(short Year)
{
    return NumberDaysInYear(Year) * 24;
}

int NumberMinutesInYear(short Year)
{
    return NumberHoursInYear(Year) * 60;
}

int NumberSecondsInYear(short Year)
{
    return NumberMinutesInYear(Year) * 60;
}


int main()
{
    short Year = ReadYear();

    cout << "Number Of Days    In Year [" << Year << "] is " << NumberDaysInYear(Year) << endl;
    cout << "Number Of Hours   In Year [" << Year << "] is " << NumberHoursInYear(Year) << endl;
    cout << "Number Of Minutes In Year [" << Year << "] is " << NumberMinutesInYear(Year) << endl;
    cout << "Number Of Seconds In Year [" << Year << "] is " << NumberSecondsInYear(Year) << endl;


    system("pause>0");
    return 0;
}
