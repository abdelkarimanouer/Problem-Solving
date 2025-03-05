#include <iostream>
#include <iomanip>
using namespace std;

int ReadNumber()
{
    int Number = 0;

    cout << "\nEnter The Number to look for in Matrix: ";
    cin >> Number;

    return Number;
}

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

bool IsNumberInMatrix(int Matrix1[3][3], int Number , short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] == Number)
                return true;
        }
    }
    return false;
}

int main()
{
    int Matrix1[3][3] = {{77, 35, 1}, {0, 8, 3}, {23, 99, 11}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    int Number = ReadNumber();

    if (IsNumberInMatrix(Matrix1, Number, 3, 3))
        cout << "\nYes it is there" << endl;
    else
        cout << "\nNo it is NOT there" << endl;

    system("pause>0");
}
