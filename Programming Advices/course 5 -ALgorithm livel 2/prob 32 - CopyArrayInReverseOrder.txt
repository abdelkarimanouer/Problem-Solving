#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To) 
{   
    int randNum = rand() % (To - From + 1) + From; 

    return randNum; 
} 

void FillArraywithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Please enter How maney elemets : " << endl;
    cin >> arrLength;

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

void CopyArrayInReverseOrder(int arr[100], int arr2[100], int arrLength)
{
    for (int i = 0 ; i < arrLength; i++)
        arr2[i] = arr[arrLength - 1 - i];
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100],  arrLength;

    FillArraywithRandomNumbers(arr, arrLength); 
   
    cout << "\nArray 1 Elements : " << endl;
    PrintArray(arr, arrLength);

    int arr2[100];
    CopyArrayInReverseOrder(arr, arr2, arrLength);

    cout << "\nArray 2 Elements After Copying array 1 in reverse order :" << endl;
    PrintArray(arr2, arrLength);

    cout << endl;

    return 0;
}

