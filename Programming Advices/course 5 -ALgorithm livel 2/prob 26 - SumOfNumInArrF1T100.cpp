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

int SumOfNumbersInArray(int arr[100], int arrLength)
{
    int SumOfNumbers = 0;
    
    for (int i = 0; i < arrLength; i++)
    {
        SumOfNumbers += arr[i]; 
    }

    return SumOfNumbers;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;   

    cout << endl;

    FillArraywithRandomNumbers(arr, arrLength);

    cout << "Array Elements : ";
    PrintArray(arr, arrLength);

    cout << "Sum of all Number Is : " << SumOfNumbersInArray(arr, arrLength) << endl;

    cout << endl;

    return 0;
}

