#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
}

void FillArray(int arr[100], int& arrLength)
{     
    arrLength = 10;

    arr[0] = 10 ;
    arr[1] = 10 ;
    arr[2] = 10 ;
    arr[3] = 50 ;
    arr[4] = 50 ;
    arr[5] = 70 ;
    arr[6] = 70 ;
    arr[7] = 70 ;
    arr[8] = 70 ;
    arr[9] = 90 ;

}

short FindNumberPositioninArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
    
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositioninArray(Number, arr, arrLength) != -1;
}

void PrintArray(int arr[100],int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;    
}

void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (!IsNumberInArray(arrSource[i], arrDestination, arrDestinationLength))
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);

        }       
    }
}

int main()
{

    int arr[100], arr2[100];
    int arrLength = 0, arr2Length = 0;   

    cout << endl;

    FillArray(arr, arrLength);

    cout << "Array 1 Elements : " << endl;
    PrintArray(arr, arrLength);

    CopyDistinctNumbersToArray(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 2 Distinct elements : " << endl;
    PrintArray(arr2, arr2Length);    

    cout << endl;

    return 0;
}

