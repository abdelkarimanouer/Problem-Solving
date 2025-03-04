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

void PrintMiddleRowOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleRow = Rows / 2;

    for (int j = 0; j < Cols; j++)
    {
        printf("%*0d      ", 2, arr[MiddleRow][j]);
    }
    cout << "\n";

}

void PrintMiddleColOfMatrix(int arr[3][3], short Rows, short Cols)
{
    short MiddleCol = Cols / 2;

    for (int j = 0; j < Rows; j++)
    {
        printf("%*0d      ", 2, arr[j][MiddleCol]);
    }
    cout << "\n";
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

    cout << "\nMiddle Row of Matrix1 is :" << endl;
    PrintMiddleRowOfMatrix(arr, 3, 3);

    cout << "\nMiddle Col of Matrix1 is :" << endl;
    PrintMiddleColOfMatrix(arr, 3, 3);

    system("pause>0");
}
