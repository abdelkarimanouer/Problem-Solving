#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

int ReadNumber()
{
    int Number = 0;

    cout << "\nEnter The Number to count in Matrix: ";
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

int main()
{

    int Matrix1[3][3] = {{9, 1, 12}, {0, 9, 1}, {0, 9, 9}};

    cout << "\nMatrix1:" << endl;
    PrintMatrix(Matrix1, 3, 3);

    int Number = ReadNumber();
    
    cout << "\nNumber " << Number << " count in Matrix is " << CountNumberInMatrix(Matrix1, Number, 3, 3) << endl;

    system("pause>0");
}
