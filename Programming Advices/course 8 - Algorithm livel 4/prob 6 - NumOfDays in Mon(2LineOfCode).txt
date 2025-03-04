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

    short NumberofDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    return (Month == 2) ? (CheckYearIsLeap(Year) ? 29 : 28) : NumberofDays[Month - 1];

}


int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();


    cout << "\nNumber Of Days    In Month [" << Year << "] is " << NumberDaysInMonth(Year, Month) << endl;

    system("pause>0");
    return 0;
}
