#include <iostream>
#include <string>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    int Number = 0;
    do
    {
        cout << Msg;
        cin >> Number;
    } while (Number <= 0);

    return Number;   
}

void ReadArray(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements : \n";
    cin >> arrLength;

    cout << "\nEnter array elements : \n";

    for (int i = 0; i < arrLength; i++)
    {
        cout << "Element [" << i + 1 << "] : ";
        cin >> arr[i];
    }
    cout << endl;

}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    
    cout << endl;
}

int TimesRepeated(int Number, int arr[100], int arrLength)
{
    int count = 0;

    for (int i = 0; i <= arrLength; i++)
    {
        if(Number == arr[i] )
            count++;
    }
    return count;
}

int main()
{
    int arr[100], arrLength, NumberToCheck;
     
    ReadArray(arr, arrLength) ;

    NumberToCheck = ReadPositiveNumber("Please enter the number you want to check : ");
    
    cout << "\nOriginal Array : ";
    PrintArray(arr, arrLength);
    
    cout << "Number " << NumberToCheck << " Is Repeated : " << TimesRepeated(NumberToCheck, arr, arrLength) << " Time(s). \n";

    return 0;
}

