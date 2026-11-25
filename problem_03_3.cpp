#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int RandomNumber(int From , int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}


void FillMatrixWithrandomNumber(int arr[3][3] , short rows , short cols)
{
    for(short i = 0; i < rows; i++)
    {
        for(short j = 0; j < cols; j++)
        {
            arr[i][j] = RandomNumber(1 , 100);
        }
    }
}


void PrintMatrix(int arr[3][3] , short rows , short cols)
{
     for(short i = 0; i < rows; i++)
    {
        for(short j = 0; j < cols; j++)
        {
            cout <<setw(3) << arr[i][j] << "   ";
        }
        cout << endl;
    }
}


int RowSum(int arr[3][3],short RowNumber, short cols)
{
    int sum = 0;

    for(short j = 0; j < cols; j++)
    {
        sum += arr[RowNumber][j];

    }
    return sum;
}


void SumMatixRowsInArry(int arr[3][3], int arrSum[3], short
rows,short cols)
{
    for(short i =0 ; i < rows;i++)
    {
        arrSum[i] = RowSum(arr, i, cols);
    }
}

void PrintRowsSumArray(int arr[3], short rows)
{
     cout << "\nThe the following are the sum of each row in the matrix:\n";
    for (short i = 0; i < rows; i++)
   {
     cout << " Row " << i + 1 << " Sum = " << arr[i] << endl;
    }
}
int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];
    FillMatrixWithrandomNumber(arr, 3, 3);
    cout << "\n The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    SumMatixRowsInArry(arr, arrSum, 3, 3);
    PrintRowsSumArray(arrSum , 3);
    return 0;
}
