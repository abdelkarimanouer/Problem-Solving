#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void FillArray(int arr[100], int& arrLength)
{     
    arrLength = 6;

    arr[0] = 10 ;
    arr[1] = 20 ;
    arr[2] = 30 ;
    arr[3] = 30 ;
    arr[4] = 20 ;
    arr[5] = 10 ;

}

void PrintArray(int arr[100],int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";

    cout << endl;    
}

bool CheckIfArrayPalindrome(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] != arr[arrLength - i - 1] )
            return false; 
    }
    return true;
}

int main()
{
    int arr[100], arrLength = 0;

    cout << endl;

    FillArray(arr, arrLength);

    cout << "Array 1 Elements : " << endl;
    PrintArray(arr, arrLength);
    
    if(CheckIfArrayPalindrome(arr, arrLength))
        cout << "Yes array is Palindrome." << endl;

    else
        cout << "No array is not Palindrome." << endl;  

    cout << endl;

    return 0;
}

