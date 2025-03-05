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

int MinNumberInArray(int arr[100], int arrLength)
{
    int Min = arr[0];
    
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }
        
    }
    return Min;
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;   

    cout << endl;

    FillArraywithRandomNumbers(arr, arrLength);

    cout << "Array Elements : ";
    PrintArray(arr, arrLength);

    cout << "Min Number Is : " << MinNumberInArray(arr, arrLength) << endl;

    cout << endl;

    return 0;
}

