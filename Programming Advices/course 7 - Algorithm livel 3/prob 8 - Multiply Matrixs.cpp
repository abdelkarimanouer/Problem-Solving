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

void MultiplyMatrixs(int Matrix1[3][3], int Matrix2[3][3], int MatrixResults[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            MatrixResults[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
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

    int Matrix1[3][3], Matrix2[3][3], MatrixResults[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    FillMatrixWithRandomNumbers(Matrix2, 3, 3);
    cout << "\nMatrix2:" << endl;
    PrintMatrix(Matrix2, 3, 3);    

    MultiplyMatrixs(Matrix1, Matrix2, MatrixResults, 3, 3);

    cout << "\nResult:" << endl;
    PrintMatrix(MatrixResults, 3, 3); 

    system("pause>0");
}
