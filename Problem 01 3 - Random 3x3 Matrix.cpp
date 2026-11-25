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
int main() {
    srand((unsigned)time(NULL));

    int arr[3][3];
    FillMatrixWithrandomNumber(arr, 3, 3);
    cout << "\n The following is a 3x3 random matrix:\n";
    PrintMatrix(arr, 3, 3);
    return 0;
}
