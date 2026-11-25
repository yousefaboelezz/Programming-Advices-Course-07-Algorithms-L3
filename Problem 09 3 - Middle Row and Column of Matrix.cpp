#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void FillMatrixWithRandomNumbers(int arr[3][3] , short Rows , short Cols)
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
            printf("%0*d    " , 2 , arr[i][j]);

          }
          cout << "\n";
     }
}
void PrintMiddleRowOfMatrix(int arr[3][3] , short Rows , short Col)
{
    short MiddleRows = Rows / 2;
    for(short j = 0 ; j < Col; j++)
    {
        printf("%0*d    " , 2 , arr[MiddleRows][j]);
    }
    cout << "\n";
}

void PrintMiddleColOfMatrix(int arr[3][3] , short Rows , short Cols)
{
    short MiddleCol = Cols / 2;
    for(short i = 0 ; i < Cols; i++)
    {
        printf("%0*d    " , 2 , arr[i][MiddleCol]);
    }
    cout << "\n";
}
int main() {

     srand((unsigned)time(NULL));

   int Matrix1[3][3];

    FillMatrixWithRandomNumbers(Matrix1, 3, 3);
    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);


    cout << "\nMiddle Row of Matrix1 is:\n";
    PrintMiddleRowOfMatrix(Matrix1 , 3 ,3);

    cout << "\nMiddle Col of Matrix1 is:\n";
    PrintMiddleColOfMatrix(Matrix1 , 3 , 3);

    return 0;
}
