#include <iostream>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3], short Rows, short Cols)
{
    int counter = 0;
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            counter++;
            arr[i][j] = counter;
            
        }
    }
}

void TransposedMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
    for (int i = 0; i < Rows; i++)
    {
        for (int j = 0; j < Cols; j++)
        {
            arrTransposed[i][j] = arr[j][i];
            
        }
    }
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

int main()
{
    int arr[3][3], arrTransposed[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:" << endl;
    PrintMatrix(arr, 3, 3);

    TransposedMatrix(arr, arrTransposed, 3, 3);
    cout << "\nThe following is the transposed matrix:" << endl;
    PrintMatrix(arrTransposed, 3,3);


    system("pause>0");

    
}
