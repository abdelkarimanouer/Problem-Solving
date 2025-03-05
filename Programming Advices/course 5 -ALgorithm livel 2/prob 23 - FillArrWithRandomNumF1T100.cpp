#include <iostream>
#include <string>
#include <ctime>
using namespace std;

float ReadPositiveNumber(string Msg)
{
    int Number = 0;
    do
    {
        cout << Msg;
        cin >> Number;
    } while (Number > 100);

    return Number;   
}

int RandomNumber(int From, int To) 
{   
    int randNum = rand() % (To - From + 1) + From; 

    return randNum; 
} 

void FillArraywithRandomNumbers(int arr[100], int& arrLength)
{
    arrLength = ReadPositiveNumber("Please Enter Max size 100 Number You want Random : ");
    

    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1,100);

}

void PrintArray(int arr[100],int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;    
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;   
   
    FillArraywithRandomNumbers(arr, arrLength);

    cout << "Array Elements : ";
    PrintArray(arr, arrLength);


    return 0;
}