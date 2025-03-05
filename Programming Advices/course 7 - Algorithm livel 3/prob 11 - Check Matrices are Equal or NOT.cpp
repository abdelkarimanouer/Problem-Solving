#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;

    return randNum;
}

void FillMatrixWithRandomNumbers(int Matrix1[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {

            Matrix1[i][j] = RandomNumber(1, 10);
        }
    }
}

int SumMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    int Sum = 0;
  
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {

            Sum += Matrix1[i][j];
        }
    }

    return Sum;
}

bool CheckEqualMatrix(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{
    return SumMatrix(Matrix1, Rows, Cols) == SumMatrix(Matrix2, Rows, Cols);
}

void PrintMatrix(int Matrix1[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            cout << setw(3);
            printf("%*0d      ", 2, Matrix1[i][j]);
        }
        cout << endl;
    }
}

int main()
{
    srand((unsigned)time(NULL));

    int Matrix1[3][3], Matrix2[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:" << endl;
    PrintMatrix(Matrix2, 3, 3);

    if (CheckEqualMatrix(Matrix1, Matrix2, 3, 3))
        cout << "\nYes: Both Matrices are equal." << endl;
    else
        cout << "\nNo: Matrices are NOT Equal." << endl;

    system("pause>0");
}
