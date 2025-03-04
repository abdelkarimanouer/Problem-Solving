#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;

    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {

            arr[i][j] = RandomNumber(1, 10);
        }
    }
}

int SumMatrix(int arr[3][3], short Rows, short Cols)
{
    int Sum = 0;
  
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {

            Sum += arr[i][j];
        }
    }

    return Sum;
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3);
            printf("%*0d      ", 2, arr[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3, 3);
    cout << "\nMatrix1:" << endl;
    PrintMatrix(arr, 3, 3);

    cout << "\nSum Of Matrix1 is : "  << SumMatrix(arr, 3, 3) << endl;

    system("pause>0");
}
