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

int main()
{
    short Year = ReadYear();

    if(CheckYearIsLeap(Year))
    {
        cout << "\nYes, " << Year << " Is Leap" << endl;
    }
    else
        cout << "\nNo, " << Year << " Is Not Leap" << endl;


    system("pause>0");
    return 0;
}
