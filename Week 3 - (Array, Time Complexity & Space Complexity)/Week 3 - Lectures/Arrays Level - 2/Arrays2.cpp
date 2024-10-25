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

int UniqueElement(int arr[], int size)
{
/*  XOR :-
    same -> 0
    Diff -> 1
*/
    int ans = 0;
    for (int i = 0; i < size; i++)
    {
        ans = ans^arr[i];
    }
    return ans;
}

void PrintPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    { 
        for (int j = 0; j < size; j++)
        {
            cout << "{" << arr[i] << ", " << arr[j] << "}" << endl;
        }
    }
}

void PairSum(int arr[], int size) //Two Sum
{   
    for (int i = 0; i < size; i++)
    { 
        for (int j = 0; j < size; j++)
        {
            cout << "{" << arr[i] << " + " << arr[j] << "} = " << arr[i] + arr[j] << endl;
        }
    }
}

void PrintTriplets(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
            cout << "{" << arr[i] << ", " << arr[j] << ", " << arr[k] << "}" << endl;
            } 
        }
    }
}

void TripletSum(int arr[], int size) //Three Sum
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
            {
            cout << "{" << arr[i] << " + " << arr[j] << " + " << arr[k] << "} = " << arr[i] + arr[j] + arr[k] << endl;
            }
        }
    }
}

void SortZeroOneCount(int arr[], int size)
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

    for (int i = 0; i < CountZero; i++)
    {
        arr[i] = 0;
    }
    for (int i = CountZero; i < size; i++)
    {
        arr[i] = 1;
    }
//  CountOne ki koi Zarurat nhi padi
}

void SortZeroOnePointer1(int arr[], int size)
{
    int low = 0;
    int high = size - 1;

    while (low < high)
    {
        while(arr[low] == 0 && low < high)
        {
            low++ ;
        }
        while(arr[high] == 1 &&  low < high)
        {
            high-- ;
        }
        swap(arr[low], arr[high]);
        // low++;
        // high--;
    }
}

void SortZeroOnePointer2(int arr[], int size)
{
    int low = 0;
    int high = size - 1;

    while (low < high)
    {
        if(arr[low] == 0 && low < high)
        {
            low++ ;
        }
        else if(arr[high] == 1 &&  low < high)
        {
            high-- ;
        }
        else
        {
        swap(arr[low++], arr[high--]);
        }
    }
}

void ShiftOneRight(int arr[], int size)
{
    int Last = arr[size - 1];
    for (int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = Last;
}

void ShiftOneLeft(int arr[], int size)
{
    int First = arr[0];
    for (int i = 0; i < size; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[size - 1] = First;
}

//Rotate array (Type-I) :-
//Rotate Single for K times
void ShiftKthRight(int arr[], int size, int k)
{
    for (int time = 0; time < k; time++)
    {
        int Last = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = Last;
    }
}

void ShiftKthLeft(int arr[], int size, int k)
{
    for (int time = 0; time < k; time++)
    {
        int First = arr[0];
        for (int i = 0; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[size - 1] = First;
    }
}

int main()
{
    int arr[9] = {2, 10, 11, 13, 10, 2, 15, 13, 15};
    int arr_size = 9;
    cout << UniqueElement(arr, arr_size) << endl;

    int brr[3] = {10, 20, 30};
    int brr_size = 3;
    // PrintPairs(brr, brr_size);

    // PairSum(brr, brr_size);

    // PrintTriplets(brr, brr_size);

    // TripletSum(brr, brr_size);

    int crr[9] = {0, 1, 0, 0, 1, 0, 0, 0, 1};
    int crr_size = 9;
    // SortZeroOneCount(crr, crr_size);
    // PrintArray(crr, crr_size);

    // SortZeroOnePointer1(crr, crr_size);
    // PrintArray(crr, crr_size);

    // SortZeroOnePointer2(crr, crr_size);
    // PrintArray(crr, crr_size);

    int drr[6] = {10, 20, 30, 40, 50, 60};
    int drr_size = 6;
    // ShiftOneRight(drr, drr_size);

    // ShiftOneLeft(drr, drr_size);

    // ShiftKthRight(drr, drr_size, 4);

    // ShiftKthLeft(drr, drr_size, 4);
    
    // PrintArray(drr, drr_size);

    return 0;
}