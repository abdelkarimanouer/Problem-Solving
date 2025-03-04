#include <iostream>
#include <iomanip>
#include <cstdio>
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

bool IsMatrixScalar(int Matrix1[3][3], short Rows, short Cols)
{
    int FirstDiagElement = Matrix1[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j && Matrix1[i][j] != FirstDiagElement)
                return false;

            else if(i != j && Matrix1[i][j] != 0)
                return false;               
        }
    }
    return true;
}

int main()
{

    int Matrix1[3][3] = {{9, 0, 0}, {0, 9, 0}, {0, 0, 9}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);


    if (IsMatrixScalar(Matrix1, 3, 3))
        cout << "\nYes: Matrix is Scalar." << endl;
    else
        cout << "\nNo: Matrix is NOT Scalar." << endl;


    system("pause>0");
}
