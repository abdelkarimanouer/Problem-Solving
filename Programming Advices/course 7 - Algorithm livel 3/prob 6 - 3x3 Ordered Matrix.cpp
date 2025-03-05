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

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    cout << "The following is a 3x3 ordered matrix:" << endl;
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

    int arr[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);
    PrintMatrix(arr, 3, 3);

    system("pause>0");

    
}
