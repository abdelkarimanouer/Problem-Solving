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

void CopyOnlyPrimeNumbers(int arrSource[100], int arrDistination[100] ,int arrLength , int& arr2Length)
{
   int counter = 0;

   for (int i = 0; i < arrLength; i++)
   {
        if (CheckPrime(arrSource[i]) == enPrimeNotPrime::Prime)
        {
            arrDistination[counter] = arrSource[i];
            counter++;
        }
   }
   arr2Length = counter; 

}

int main()
{
    srand((unsigned)time(NULL));

    int arr[100], arrLength;   

    cout << endl;

    FillArraywithRandomNumbers(arr, arrLength);
   
    int arr2[100], arr2Length;
    CopyOnlyPrimeNumbers(arr, arr2, arrLength, arr2Length);
 
    cout << "Array 1 Elements : " << endl;
    PrintArray(arr, arrLength);
    
    cout << "\nPrime Numbers in Array 2 is : " << endl;
    PrintArray(arr2, arr2Length);

    cout << endl;

    return 0;
}

