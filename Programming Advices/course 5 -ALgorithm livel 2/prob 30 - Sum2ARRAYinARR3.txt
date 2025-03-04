#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
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

int RandomNumber(int From, int To) 
{   
    int randNum = rand() % (To - From + 1) + From; 

    return randNum; 
} 

void FillArraywithRandomNumbers(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    { 
        arr[i] = RandomNumber(1,100);
    }
}

void PrintArray(int arr[100],int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;    
}

void SumOf2Array(int arr[100], int arr2[100], int Sumarr[100], int arrLength)
{    
    for (int i = 0; i < arrLength; i++)
    {
        Sumarr[i] = arr[i] + arr2[i] ; 
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100],arr2[100], Sumarr[100] ; 
    int arrLength = ReadPositiveNumber("Please enter How many elements :");

    FillArraywithRandomNumbers(arr, arrLength);
    FillArraywithRandomNumbers(arr2, arrLength);
 
    SumOf2Array(arr, arr2, Sumarr, arrLength);

    cout << "\nArray 1 Elements : " << endl;
    PrintArray(arr, arrLength);

    cout << "\nArray 2 Elements :" << endl;
    PrintArray(arr2, arrLength);

    cout << "\nSum Array 1 and Array 2 is :" << endl;
    PrintArray(Sumarr, arrLength);

    cout << endl;

    return 0;
}

