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
    if(Year % 400 == 0)
    {
        return true;
    }

    else if(Year % 100 == 0)
    {
        return false;
    }

    else if (Year % 4 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

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
