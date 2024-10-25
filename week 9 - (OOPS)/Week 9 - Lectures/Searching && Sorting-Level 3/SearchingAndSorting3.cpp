#include <iostream>
using namespace std;

int GetQuotient(int divisor, int dividend)
{
    int s = 0;
    int e = dividend;
    int mid;
    int ans = 0;

    while (s <= e)
    {
        mid = (s + e)/2;
        if (mid*divisor == dividend)
        {
            return mid;
        }
        else if (mid*divisor < dividend)
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

int SearchNearlySorted(int arr[], int n, int target)
{
    int s = 0;
    int e = n-1;
    int mid;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if ((mid - 1) >= 0 && arr[mid - 1] == target)
        {
            return mid - 1;
        }
        else if ((mid + 1) < n && arr[mid + 1] == target)
        {
            return mid + 1;
        }
        else if (arr[mid] < target)
        {
            s = mid + 2;
        }
        else
        {
            e = mid - 2;
        }
    }
    return -1;
}

int OddOccur(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid;

    while (s <= e)
    {
        mid = (s + e) / 2;
        if (s == e)
        {
            cout << "Index : " << mid << endl << "Number : ";
            return arr[mid];
        }
        else if (mid & 1) //mid&1 --> true --> Odd
        {
            if (arr[mid - 1] == arr[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        else //mid&1 --> false --> Even
        {
            if (mid + 1 < n && arr[mid] == arr[mid + 1])
            {
                s = mid + 2;
            }
            else
            {
                e = mid; //At Answer or at Right Part
            }
        }
    }
    return -1;
}

int main()
{
    int divisor = -7;
    int dividend = -29;

    // int ans = GetQuotient(abs(divisor), abs(dividend));
    // if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0))
    // {
    //     ans = -ans;
    // }
    // cout << "Final ans is : " << ans  << endl;

    int arr[] = {20, 10, 30, 50, 40, 70, 60};
    int arr_size = 7;
    int target = 70;

    // cout << SearchNearlySorted(arr, arr_size, target) << endl;

    int brr[] = {3};
    int brr_size = 1;

    // cout << OddOccur(brr, brr_size) << endl;

    return 0;
}