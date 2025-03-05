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

bool IsMatrixIdentity(int Matrix1[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            if (i == j && Matrix1[i][j] != 1)
                return false;

            else if(i != j && Matrix1[i][j] != 0)
                return false;               
        }
    }
    return true;
}

int main()
{

    int Matrix1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);


    if (IsMatrixIdentity(Matrix1, 3, 3))
        cout << "\nYes: Matrix is identity." << endl;
    else
        cout << "\nNo: Matrix is NOT identity." << endl;


    system("pause>0");
}
