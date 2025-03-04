#include <iostream>
#include <iomanip>
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
            arr[i][j] = RandomNumber(1,100);
        }
    }

}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
    cout << "The following is a 3x3 random matrix:" << endl;
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
    srand((unsigned)time(NULL));

    int arr[3][3];

    FillMatrixWithRandomNumbers(arr, 3,3);
    PrintMatrix(arr,3,3);

    system("pause>0");

}