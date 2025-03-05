#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
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

short FindNumberPositioninArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i;
    }
    return -1;
    
}

int main()
{
    srand((unsigned)time(NULL));
    
    cout << endl;

    int arr[100], arrLength;
   
    FillArraywithRandomNumbers(arr, arrLength);

    cout << "Array Elements : ";
    PrintArray(arr, arrLength);

    int Number = ReadPositiveNumber("\nPlease enter a number to search for : ");
    cout << "\nNumber You are Looking for is : " << Number << endl << endl;
           
    short NumberPosition = FindNumberPositioninArray(Number, arr, arrLength);

    if (NumberPosition == -1)
        cout << "The number is not found :(" << endl;
    else
    {
        cout << "The Number found at Position : " << NumberPosition << endl;
        cout << "The Number found its order : " << NumberPosition + 1 << endl; 
    }

    cout << endl;
    return 0;
}
