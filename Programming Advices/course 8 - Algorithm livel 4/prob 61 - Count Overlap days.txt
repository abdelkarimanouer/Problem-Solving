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

bool IsDate1BeforeDate2(sDate Date1, sDate Date2)
{
    return ( Date1.Year < Date2.Year) ? true : ( (Date1.Year == Date2.Year) ? ( Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false )) : false );
}

bool IsDate1EqualDate2(sDate Date1, sDate Date2)
{
    return  (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false; 
}

enCompareDate CompareDateResult(sDate Date1, sDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enCompareDate::Before;
    else if(IsDate1EqualDate2(Date1, Date2))
        return enCompareDate::Equal;

    return enCompareDate::After;
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

int DeffrenceBetweenDate1AndDate2(sDate Date1, sDate Date2, bool IncludLastDay = false)
{    
    int Days = 0;

    while (IsDate1BeforeDate2(Date1, Date2))
    {
        Days++;
        Date1 = IncreaseDateByOneDay(Date1);
    }

    return IncludLastDay ? ++Days : Days ;
    
}

int PeriodLength(sPeriod Period, bool IncludEndDay = false)
{
    return DeffrenceBetweenDate1AndDate2(Period.StartDate, Period.EndDate, IncludEndDay);
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

bool IsDateinPeriod(sPeriod Period, sDate DateToCheck)
{
    return !( CompareDateResult(DateToCheck, Period.StartDate) == enCompareDate::Before 
              ||
              CompareDateResult(DateToCheck, Period.EndDate) == enCompareDate::After
            ) ;
}

int CountOverlapDays(sPeriod Period1, sPeriod Period2) 
{ 
    int Period1Length = PeriodLength(Period1, true); 
    int Period2Length = PeriodLength(Period2, true); 
    int OverlapDays = 0; 
    
    if (!IsOverlapPeriods(Period1, Period2)) 
        return 0; 
    
    if (Period1Length < Period2Length)     
    { 
        while (IsDate1BeforeDate2(Period1.StartDate, Period1.EndDate))         
        { 
            if (IsDateinPeriod(Period2, Period1.StartDate))                 
                OverlapDays++; 

            Period1.StartDate = IncreaseDateByOneDay(Period1.StartDate);         
        }     
    } 
    
    else    
    { 
        while (IsDate1BeforeDate2(Period2.StartDate, Period2.EndDate))         
        { 
            if (IsDateinPeriod(Period2, Period1.StartDate))                 
                OverlapDays++; 
                
            Period2.StartDate = IncreaseDateByOneDay(Period2.StartDate);         
        }     
    } 
    
    return OverlapDays; 
} 

int main()
{
    cout << "\nEnter Period 1: \n";
    sPeriod Period1 = ReadPeriod();

//----------------------------------------------------
    cout << "\nEnter Period 2: \n";
    sPeriod Period2 = ReadPeriod();
        
    cout << "\nOverlap Days Count is : " << CountOverlapDays(Period1, Period2) << endl;


    cout << endl;
    system("pause>0");
    return 0;
}

