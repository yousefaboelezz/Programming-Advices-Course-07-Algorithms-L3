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


int ColSum(int arr[3][3],short ColNumber, short rows)
{
    int sum = 0;

    for(short i = 0; i < rows; i++)
    {
        sum += arr[i][ColNumber];

    }
    return sum;
}


void SumMatixColInArry(int arr[3][3], int arrSum[3], short
rows,short cols)
{
    for(short j =0 ; j < cols;j++)
    {
        arrSum[j] = ColSum(arr, j, rows);
    }
}

void PrintColSumArray(int arr[3], short rows)
{
     cout << "\nThe the following are the sum of each Col in the matrix:\n";
    for (short i = 0; i < rows; i++)
   {
     cout << " Col " << i + 1 << " Sum = " << arr[i] << endl;
    }
}
int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    int arrSum[3];
    FillMatrixWithrandomNumber(arr, 3, 3);
    cout << "\n The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    SumMatixColInArry(arr, arrSum, 3, 3);
    PrintColSumArray(arrSum , 3);
    return 0;
}
