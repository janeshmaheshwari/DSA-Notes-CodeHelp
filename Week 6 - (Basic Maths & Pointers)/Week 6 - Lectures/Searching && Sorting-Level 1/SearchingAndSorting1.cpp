#include <iostream>
using namespace std;

int BinarySearch(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (target == arr[mid])
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

int FirstOccur(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid;
    int ans = -1;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (target == arr[mid])
        {
            ans = mid;
            e = mid - 1;
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
    return ans;
}

int LastOccur(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid;
    int ans = -1;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (target == arr[mid])
        {
            ans = mid;
            s = mid + 1;
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
    return ans;
}

int TotalOccur(int arr[], int size, int target)
{
    int s = 0;
    int e = size - 1;
    int mid;
    int first = -1;
    int last = -1;

    while (s <= e)
    {
        mid = (s + e)/2;
        if (target == arr[mid])
        {
            first = mid;
            e = mid - 1;
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

    s = 0;
    e = size - 1;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (target == arr[mid])
        {
            last = mid;
            s = mid + 1;
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

    return last - first + 1;
}

int MissingNumber1(int arr[], int size) // ???
{
    int s = 0;
    int e = size - 1;
    int ans = -1;
    int mid = (s + e)/2;

    while(s < e)
    {
        int diff = arr[mid] - mid;

        if(diff == 1)
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
        mid = (s + e)/2;
    }

    if(ans + 1 == 0)
    {
        return size + 1;
    }
  
    return ans + 1;
}

//[Any Start Value - n]
int MissingNumber2(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int gap = arr[s] - s; //Only Applicable if First Number is not Missing
    int mid;
    int diff;
    int ans = -1;
    while (s <= e)
    {
        mid = (s + e)/2;
        diff = arr[mid] - mid;

        if (diff == gap)
        {
            s = mid + 1;
        }
        else
        {
            ans = mid;
            e = mid - 1;
        }
    }
    if (arr[ans] - 1 > arr[e])
    {
        return arr[e] + 1;
    }
    return arr[ans] - 1;
}

int PeakIndex(int arr[], int size)
{
    int s = 0;
    int e = size - 1;
    int mid;
    int ans;

    while (s < e)
    {
        mid = (s + e)/2;

        if(arr[mid] < arr[mid + 1])
        {
            s = mid + 1;
        }
        else
        {
            ans = arr[mid];
            e = mid;
        }
    }
    return ans;
}

int main()
{
    int arr[9] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int arr_size = 9;
    int arr_target = 100;

    // cout << BinarySearch(arr, arr_size, arr_target);

    int brr[8] = {10, 20, 30, 30, 30, 30, 40, 50};
    int brr_size = 8;
    int brr_target = 30;

    // cout << FirstOccur(brr, brr_size, brr_target) << endl;
    // cout << LastOccur(brr, brr_size, brr_target) << endl;
    // cout << TotalOccur(brr, brr_size, brr_target) << endl;

    int crr[8] = {0,1, 2,3,4,5,6,7};
    int crr_size = 8;

    cout << MissingNumber1(crr, crr_size) << endl; // ???
    
    int drr[8] = {3, 4, 5, 6, 7, 8, 9, 10};
    int drr_size = 8;

    // cout << MissingNumber2(drr, drr_size) << endl;

    int err[5] = {10, 40, 30, 20, 10};
    int err_size = 5;

    // cout << PeakIndex(err, err_size) << endl;

    return 0;
}