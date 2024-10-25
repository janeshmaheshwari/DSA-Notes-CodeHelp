#include <iostream>
using namespace std;

//col * (i+1) + j

// for 2D array atleast columns aree required to give.
// arr[][4]

void PrintRowWise(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

//Printing a Transpose Matrix For a Non Square Matrix
void PrintColWise(int arr[][4], int row, int col) 
{
    for (int j = 0; j < col; j++)
    {
        for (int i = 0; i < row; i++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool MatrixSearch(int arr[][4], int row, int col, int target)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (target == arr[i][j])
            {
                return true;
            }
        }
    }
    return false;
}

int FindMax(int arr[][4], int row, int col)
{
    int max = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
            }
        }
    }
    return max;
}

int FindMin(int arr[][4], int row, int col)
{
    int min = arr[0][0];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] < min)
            {
                min = arr[i][j];
            }
        }
    }
    return min;
}

void RowWiseSum(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        int RowSum = 0;
        for (int j = 0; j < col; j++)
        {
            RowSum += arr[i][j];
        }
        cout << RowSum << endl;
    }
}

void ColWiseSum(int arr[][4], int row, int col)
{
    for (int j = 0; j < col; j++)
    {
        int ColSum = 0;
        for (int i = 0; i < row; i++)
        {
            ColSum += arr[i][j];
        }
        cout << ColSum << endl;
    }
}

int DiagonalSum(int arr[][4], int row)
{
    int DiagSum = 0;
    for (int i = 0; i < row; i++)
    {
        DiagSum += arr[i][i];
    }
    return DiagSum;
}

int OffDiagonalSum(int arr[][4], int row)
{
    int OffDiagSum = 0;
    for (int i = 0; i < row; i++)
    {
        OffDiagSum += arr[i][row - i - 1];
    }
    return OffDiagSum;
}

void Transpose(int arr[][4], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = i + 1; j < col; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }
    cout << endl;
}

int main()
{
    int arr[3][4]={{10, 20, 11, 21}, {30, 40, 31, 41}, {50, 60, 51, 61}};
    int arr_row = 3;
    int arr_col = 4;

    PrintRowWise(arr, arr_row, arr_col);
    
    // PrintColWise(arr, arr_row, arr_col); //Transpose for Non-Square(Rectangular) Matrix

    // cout << MatrixSearch(arr, arr_row, arr_col, 21) << endl;

    // cout << FindMax(arr, arr_row, arr_col) << endl;

    // cout << FindMin(arr, arr_row, arr_col) << endl;

    // RowWiseSum(arr, arr_row, arr_col);

    // ColWiseSum(arr, arr_row, arr_col);

    // cout << DiagonalSum(arr, arr_row) << endl;

    // cout << OffDiagonalSum(arr, arr_row) << endl; // 10, 60, 31, 81

    int brr[4][4]={{10, 20, 30, 40}, {50, 60, 70, 80}, {11, 21, 31, 41}, {51, 61, 71, 81}};
    int brr_row = 4;
    int brr_col = 4;

    // PrintRowWise(brr, brr_row, brr_col);

    // Transpose(brr, brr_row, brr_col);

    // PrintRowWise(brr, brr_row, brr_col);

    return 0;
}