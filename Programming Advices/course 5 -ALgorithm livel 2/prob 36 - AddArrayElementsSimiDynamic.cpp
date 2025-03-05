#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

int ReadNumber()
{
    int Number = 0;

    cout << "\nPlease enter a Number : ";
    cin >> Number;

    return Number;
}

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void InputUserNumbersInArray(int arr[100], int& arrLength)
{
    bool Answer = true;

    do
    {
        AddArrayElement(ReadNumber(),arr, arrLength);
        
        cout << "Do You want enter more numbers : [0]:NO // [1]: Yes :";
        cin >> Answer;

    } while (Answer);
    
}

void PrintArray(int arr[100],int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;    
}

int main()
{
    int arr[100], arrLength = 0;

    InputUserNumbersInArray(arr, arrLength);

    cout << "\nArray Length is : " << arrLength << endl;
    cout << "Array Elements : ";
    PrintArray(arr, arrLength);

    cout << endl;
    return 0;
}