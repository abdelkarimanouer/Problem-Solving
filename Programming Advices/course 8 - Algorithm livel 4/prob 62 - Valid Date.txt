#include <iostream>
using namespace std;

enum enCompareDate{ Before = -1, Equal = 0, After = 1};

struct stDate
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

stDate ReadFullDate()
{
    stDate Date;

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

bool IsValidDate(stDate Date) 
{ 
    if (Date.Day < 1 || Date.Day > 31) 
        return false; 
    
    if (Date.Month < 1 || Date.Month > 12) 
        return false; 
    
    if (Date.Month == 2)       
    { 
        if (CheckYearIsLeap(Date.Year))             
        { 
            if (Date.Day > 29) 
                return false;             
        } 
        else            
        {  
            if (Date.Day > 28) 
                return false;             
        }     
    } 
    
    short DaysInMonth = NumberDaysInMonth(Date.Year, Date.Month); 
    
    if (Date.Day > DaysInMonth) 
        return false; 
    
    return true;
}


int main()
{
    cout << "\nEnter Date: \n";
    stDate Date = ReadFullDate();

    if (IsValidDate(Date))
        cout << "\nYes, Date is Validate." << endl;
    else
        cout << "\nNo, Date is Not Validate." << endl;



    cout << endl;
    system("pause>0");
    return 0;
}

