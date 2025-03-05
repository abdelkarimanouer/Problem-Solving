#include <iostream>
#include <string>
#include <ctime>
using namespace std;

int RandomNumber(int From, int To) 
{   
    int randNum = rand() % (To - From + 1) + From; 

    return randNum; 
} 

void FillArraywithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "Please Enter Max size 100 Number You want Random : " << endl;    
    cin >> arrLength;
    
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1,100);

}

void PrintArray(int arr[100],int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;    
}

void CopyArray(int arrSource[100], int arrDestination[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        arrDestination[i] = arrSource[i];
    
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;   

    cout << endl;

    FillArraywithRandomNumbers(arr, arrLength);

    int arr2[100];
    CopyArray(arr, arr2, arrLength);

    cout << "Array 1 Elements : " << endl;
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Elements after Copy : " << endl;
    PrintArray(arr2, arrLength);    

    cout << endl;

    return 0;
}

