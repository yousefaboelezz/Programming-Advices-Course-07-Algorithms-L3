#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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

short CountNumberInMatrix(int Matrix1[3][3], int Number, short Rows, short Cols)
{
       short NumberCount = 0;
       for (short i = 0; i < Rows; i++)
           {
               for (short j = 0; j < Cols; j++)
                   {
                      if (Matrix1[i][j] == Number)
                         {
                             NumberCount++;
                         };
                   }
            }
          return NumberCount;
}

int main() {

    int Matrix1[3][3] = { {8,1,2},{5,9,1},{3,9,5} };


    cout << "\nMatrix1:\n";
    PrintMatrix(Matrix1, 3, 3);

   int Number;
   cout << "\nEnter the number to count in matrix? ";
   cin >> Number;

  if (CountNumberInMatrix(Matrix1, Number, 3, 3) > 0)
      cout << "\nYes it is there.\n";
  else
      cout << "\nNo: It's NOT there.\n";


    return 0;
}
