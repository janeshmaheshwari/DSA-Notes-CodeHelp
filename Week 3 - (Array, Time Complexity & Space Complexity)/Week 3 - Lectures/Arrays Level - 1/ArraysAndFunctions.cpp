#include <iostream>
using namespace std;

void PrintArray(int arr[], int size)
{
    cout << "{ ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "}" << endl;
}

bool linearSearch(int arr[], int size, int target)
{
    for (int i = 0; i < size; i++)
    {
        if (target == arr[i])
        {
            return true;
        }
    }
    return false;
}

void CountZeroOne(int arr[], int size)
{
    int CountZero = 0;
    int CountOne = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
        {
            CountZero++ ;
        }
        else
        {
            CountOne++ ;
        }
    }
    cout << "Number of 0's : " << CountZero << endl << "Number of 1's : " << CountOne << endl;
}

int MinNum(int arr[], int size)
{
    int Min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < Min)
        {
            Min = arr[i];
        }   
    }
    return Min;
}

void ExtremePrint(int arr[], int size)
{
    int left = 0;
    int right = size - 1;

    cout << "{ ";
    while (left <= right)
    {
        if (left == right)
        {
            cout << arr[left] << " ";
        }
        else
        {
        cout << arr[left] << " ";
        cout << arr[right] << " ";
        }
        left++ ;
        right-- ;
    }
    cout << "}" << endl;
}

/*  Reversing the Array :-
1.  Swap - (Two Pointer Approach) 2. Swap - (Left & Right)
eg: Left = arr[i] & Right = arr[size - i - 1]
3.  Temporary Variable
4.  Arithmetic - (+/-)
5.  XOR
*/

void ReverseSwapTwoPointer(int arr[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        swap(arr[i], arr[size - i - 1]);
    }
}

void ReverseSwapLeftRight(int arr[], int size) //Work in Progress
{
    int left = 0;
    int right = size - 1;

    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++ ;
        right-- ;
    }
}

void ReverseTempVar(int arr[], int size)
{
    int Temp = 0;
    for (int i = 0; i < size/2; i++)
    {
        Temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = Temp;
    }
}

void ReverseArithmetic(int arr[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        arr[i] = arr[i] + arr[size - 1 - i];
        arr[size - 1 - i] = arr[i] - arr[size - 1 - i];
        arr[i] = arr[i] - arr[size - 1 - i];
    }
}

void ReverseXOR(int arr[], int size)
{
    for (int i = 0; i < size/2; i++)
    {
        arr[i] = arr[i] ^ arr[size - 1 - i];
        arr[size - 1 - i] = arr[i] ^ arr[size - 1 - i];
        arr[i] = arr[i] ^ arr[size - 1 - i];
    }
}

int main()
{
    int arr[5] = {6, 10, 2, 8, 4};
    int arr_size = 5;
    int target = 8;

    int brr[8] = {1, 0, 1, 1, 0, 0, 1, 1};
    int brr_size = 8;

    // ReverseSwapTwoPointer(arr, arr_size);

    // ReverseSwapLeftRight(arr, arr_size);

    // ReverseTempVar(arr, arr_size);

    // ReverseArithmetic(arr, arr_size);

    ReverseXOR(arr, arr_size);

    PrintArray(arr, arr_size);

    // CountZeroOne(brr, brr_size);

    // if (linearSearch(arr, arr_size, target))
    // {
    //     cout << "Target Found !" << endl;
    // }
    // else
    // {
    //     cout << "Target Not Found !" << endl;
    // }

    // cout << MinNum(arr, arr_size) << endl;

    // ExtremePrint(arr, arr_size);

    return 0;
}