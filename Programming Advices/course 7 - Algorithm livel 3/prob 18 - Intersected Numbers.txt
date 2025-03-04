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

void IntersectedNumbers(int Matrix1[3][3], int Matrix2[3][3], short Rows, short Cols)
{ 
    int Number;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {            
            Number = Matrix1[i][j];

            if(IsNumberInMatrix(Matrix2, Number, Rows, Cols))
                cout << setw(3) << Number << "     ";
        }
    }
    cout << endl;
}

int main()
{
    int Matrix1[3][3] = {{77, 66, 1}, {0, 8, 3}, {23, 4, 11}};
    int Matrix2[3][3] = {{6, 55, 77}, {9, 4, 5}, {80, 8, 11}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    cout << "\nMatrix2:" << endl;
    PrintMatrix(Matrix2, 3, 3);

    cout << "Intersected Numbers are: " << endl;    
    IntersectedNumbers(Matrix1, Matrix2, 3, 3);


    system("pause>0");
}
