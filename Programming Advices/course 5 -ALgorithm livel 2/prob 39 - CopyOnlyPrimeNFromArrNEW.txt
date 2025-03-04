#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
using namespace std;

enum enPrimeNotPrime {Prime = 1 , NotPrime = 2};

int RandomNumber(int From, int To) 
{   
    int randNum = rand() % (To - From + 1) + From; 

    return randNum; 
} 

void AddArrayElement(int Number, int arr[100], int& arrLength)
{
    arrLength++;
    arr[arrLength - 1] = Number;
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

enPrimeNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return enPrimeNotPrime::NotPrime;
        
    }
    return enPrimeNotPrime::Prime;

}

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
        }
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength = 0, arr2Length = 0;   

    cout << endl;

    FillArraywithRandomNumbers(arr, arrLength);

    int arr2[100];
    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);

    cout << "Array 1 Elements : " << endl;
    PrintArray(arr, arrLength);
    cout << "\nArray 2 Prime Numbers : " << endl;
    PrintArray(arr2, arr2Length);    

    cout << endl;

    return 0;
}

