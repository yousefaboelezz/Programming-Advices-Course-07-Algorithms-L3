#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

void FillMatrixWithOrderedNumbers(int arr[3][3] , short Rows , short Cols)
{
    short Count = 1;
    for(int i = 0; i < Rows; i++)
    {
        for(int j = 0; j < Cols; j++)
        {
            arr[i][j] = Count++;
        }
    }
}

void PrintMatrix(int arr[3][3], short Rows, short Cols)
{
     for (short i = 0; i < Rows; i++)
     {
          for (short j = 0; j < Cols; j++)
          {
               cout << setw(3) << arr[i][j] << " ";
          }
          cout << "\n";
     }
}

void TransposeMatrix(int arr[3][3], int arrTransposed[3][3], short Rows, short Cols)
{
        for (short i = 0; i < Rows; i++)
        {
               for (short j = 0; j < Cols; j++)
               {
                      arrTransposed[i][j] = arr[j][i];
               }
        }
}

int main() {
    int arr[3][3];
    int arrTransposed[3][3];

    FillMatrixWithOrderedNumbers(arr, 3, 3);
    cout << "\nThe following is a 3x3 ordered matrix:\n";
    PrintMatrix(arr, 3, 3);

    TransposeMatrix(arr, arrTransposed, 3, 3);
    cout << "\n\nThe following is the transposed matrix:\n";
    PrintMatrix(arrTransposed, 3, 3);

    return 0;
}
