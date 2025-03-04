#include <iostream>
using namespace std;

enum enCompareDate{ Before = -1, Equal = 0, After = 1};

struct sDate
{
    short Year;
    short Month;
    short Day;
};

struct sPeriod
{
    sDate StartDate;
    sDate EndDate;
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

sPeriod ReadPeriod()
{
    sPeriod Period;

    cout << "Enter Start Date: \n";
    Period.StartDate.Day = ReadDay();
    Period.StartDate.Month = ReadMonth();
    Period.StartDate.Year = ReadYear();

    cout << "\nEnter End Date: \n";
    Period.EndDate.Day = ReadDay();
    Period.EndDate.Month = ReadMonth();
    Period.EndDate.Year = ReadYear();

    return Period;
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

enCompareDate CompareDateResult(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;
    else if(IsDate1EqualDate2(Date1, Date2))
        return enCompareDate::Equal;

    return enCompareDate::After;
}

bool IsOverlapPeriods(sPeriod Period1, sPeriod Period2)
{
    if ( CompareDateResult(Period2.EndDate, Period1.StartDate ) == enCompareDate::Before
         || 
         CompareDateResult(Period2.StartDate, Period1.EndDate) == enCompareDate::After
       )
        return false; 
    else
        return true;
}


int main()
{
    cout << "\nEnter Period 1: \n";
    sPeriod Period1 = ReadPeriod();

//----------------------------------------------------
    cout << "\nEnter Period 2: \n";
    sPeriod Period2 = ReadPeriod();


    
    if (IsOverlapPeriods(Period1, Period2))
        cout << "\nYes, Periods Overlap." << endl;
    else
        cout << "\nNo, Periods Not Overlap." << endl;
    


    cout << endl;
    system("pause>0");
    return 0;
}

