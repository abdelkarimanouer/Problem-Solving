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

    cout << "=> Enter Year? ";
    cin >> Year;

    return Year;
}

short ReadDay()
{
    short Day;

    cout << "\n=> Enter Day? ";
    cin >> Day;

    return Day;
}

short ReadMonth()
{
    short Month;

    cout << "=> Enter Month? ";
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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return ( Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? ( Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false )) : false );
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
}

bool IsDate1AfterDate2(sDate Date1, sDate Date2)
{
    return ( !IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2) ) ;
}


int main()
{
    cout << "\nEnter Date1: \n";
    sDate Date1 = ReadFullDate();

    cout << "\nEnter Date2: \n";
    sDate Date2 = ReadFullDate();
    
    if (IsDate1AfterDate2(Date1, Date2))
    {
        cout << "\nYes, Date1 is After than Date2." << endl;
    }
    else
        cout << "\nNo, Date1 is Not After Than Date2." << endl;



    cout << endl;
    system("pause>0");
    return 0;
}

