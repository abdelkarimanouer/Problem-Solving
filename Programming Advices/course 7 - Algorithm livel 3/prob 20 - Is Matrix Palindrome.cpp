#include <iostream>
#include <iomanip>
using namespace std;

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3) << arr[i][j] << "     ";
        }
        cout << endl;
    }
}

bool IsPalindromeMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols / 2; j++)
        {
            if(Matrix1[i][j] != Matrix1[i][Cols - 1 - j])
            {
                return false;
            }
        }
    }   
    return true;
}

int main()
{
    int Matrix1[3][3] = {{1, 2, 1}, {5, 5, 5}, {7, 3, 7}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    if (IsPalindromeMatrix(Matrix1, 3, 3))
        cout << "\nYes: Matrix is Palindrome." << endl;
        
    else
        cout << "No: Matrix is NOT Palindrome." << endl;
    

    system("pause>0");
}

