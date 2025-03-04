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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
    short CountNumber = 0;

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
                CountNumber++;
        }
    }
    
    return CountNumber;
}

bool IsMatrixSparse(int Matrix1[3][3], short Rows, short Cols)
{
    short MaxSize = Rows * Cols;

    return CountNumberInMatrix(Matrix1, 0, 3, 3) >= (MaxSize / 2);
}


int main()
{
    int Matrix1[3][3] = {{9, 0, 1}, {0, 9, 0}, {0, 0, 9}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    if (IsMatrixSparse(Matrix1, 3, 3))
        cout << "\nYes: Matrix is Sparse." << endl;
    else
        cout << "\nNo: Matrix is NOT Sparse." << endl;

    system("pause>0");
}
