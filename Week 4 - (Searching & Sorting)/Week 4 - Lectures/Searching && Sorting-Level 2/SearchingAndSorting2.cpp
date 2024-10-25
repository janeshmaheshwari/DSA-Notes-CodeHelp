#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

int FindPivotIndex(vector<int> arr)
{
    int s = 0;
    int e = arr.size() - 1;
    int mid;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (s == e)
        {
            return mid;
        }
        else if (mid + 1 < arr.size() && arr[mid] > arr[mid + 1])
        {
            return mid;
        }
        else if(mid - 1 >= 0 && arr[mid] < arr[mid - 1])
        {
            return mid - 1;
        }
        else if (arr[s] > arr[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return -1;
}

int BinarySearch(vector<int> arr, int s, int e, int target)
{
    int mid;
    while(s <= e)
    {
        mid = (s + e)/2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (target > arr[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int Search(vector<int> arr, int target)
{
    int PivotIndex = FindPivotIndex(arr);
    int ans = -1;
    
    if (target >= arr[0] && target <= arr[PivotIndex])
    {
        ans = BinarySearch(arr, 0, PivotIndex, target);
    }
    else if (target >= arr[PivotIndex] && target <= arr[arr.size() - 1])
    {
        ans = BinarySearch(arr, PivotIndex + 1, arr.size() - 1, target);
    }
    return ans;
}

int MySqrt(int x)
{
    int s = 0;
    int e = x;
    long long int mid;
    int ans = -1;
    while (s <= e)
    {
        mid = s + (e - s)/2;
        if (mid*mid == x)
        {
            return mid;
        }
        else if (mid*mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

double MySqrtDecimal(int x, int decimal)
{
    int s = 0;
    int e = x;
    long long int mid;
    double ans = -1;
    while (s <= e)
    {
        mid = s + (e - s)/2;
        if (mid*mid == x)
        {
            return mid;
        }
        else if (mid*mid < x)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    double step = 0.1;
    for (int i = 0; i < decimal; i++)
    {
        double j = ans; 
        while (j*j <= x)
        {
            ans = j;
            j += step;
        }
        step /= 10;
    }
    return ans;
}

bool SearchMatrix(vector<vector<int>>& nums, int target)
{
    int row = nums.size();
    int col = nums[0].size();
    int n = row*col;

    int s = 0;
    int e = n-1;
    int mid;

    while (s <= e)
    {
        mid = (s + e)/2;
        int rowIndex = mid/col;
        int colIndex = mid % col;
        int currNumber = nums[rowIndex][colIndex];

        if (currNumber == target)
        {
            cout << target << " at (" << rowIndex << ", " << colIndex << ")" << endl;
            return true;
        }
        else if (currNumber < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}

double MyDivideDecimal(int Dividend, int Divisor, int decimal)
{
    int s = 0, e = Dividend;
    int ans = 0;
    int mid;
    while (s <= e)
    {
        mid = (e - s) / 2 + s;
        if (mid * Divisor <= Dividend)
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    double quotient = ans;
    double step = 0.1;
    for (int i = 0; i < decimal; ++i)
    {
        double j = quotient;
        while (j * Divisor <= Dividend)
        {
            quotient = j;
            j += step;
        }
        step /= 10;
    }
    return quotient;
}

int main()
{
    vector<int> arr = {12, 14, 16, 2, 4, 6, 8, 10};
    int target_arr = 16;

    // cout << FindPivotIndex(arr) << endl;
    // cout << Search(arr, target_arr) << endl;

    // cout << MySqrt(64) << endl;
    // cout << MySqrtDecimal(51, 10) << endl;
    // printf("%0.10f", MySqrtDecimal(51, 10));

    vector<vector<int>> brr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int brr_target = 7;
    // cout << SearchMatrix(brr, brr_target) << endl;

    cout << MyDivideDecimal(22, 7, 10) << endl;
    printf("%0.15f", MyDivideDecimal(22, 7, 15));

    return 0;
}