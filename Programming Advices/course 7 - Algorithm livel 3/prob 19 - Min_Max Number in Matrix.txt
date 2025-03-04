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

int MinimumNumber(int Matrix1[3][3], short Rows, short Cols)
{
    short MinNum = Matrix1[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] < MinNum)
            {
                MinNum = Matrix1[i][j];
            }
        }
    }
    return MinNum;
}

int MaximumNumber(int Matrix1[3][3], short Rows, short Cols)
{
    short MaxNum = Matrix1[0][0];

    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] > MaxNum)
            {
                MaxNum= Matrix1[i][j];
            }
        }
    }
    return MaxNum;
}

int main()
{
    int Matrix1[3][3] = {{77, 66, 5}, {7, 8, 3}, {23, 4, 11}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMinimum Number is: " << MinimumNumber(Matrix1, 3, 3) << endl;
    cout << "\nMaximum Number is: " << MaximumNumber(Matrix1, 3, 3) << endl;

    system("pause>0");
}
