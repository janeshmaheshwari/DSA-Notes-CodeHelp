#include <iostream>
using namespace std;

void merge(int arr[], int s, int e)
{
    int mid = (s + e)/2;
    int lenLeft = mid - s + 1;
    int lenRight = e - mid;

    int *left = new int[lenLeft];
    int *right = new int[lenRight];

    int k = s;
    for (int i = 0; i < lenLeft; i++)
    {
        left[i] = arr[k];
        k++ ;
    }
    
    k = mid + 1;
    for (int i = 0; i < lenRight; i++)
    {
        right[i] = arr[k];
        k++ ;
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mainArrayIndex = s;

    while (leftIndex < lenLeft && rightIndex < lenRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainArrayIndex] = left[leftIndex];
            mainArrayIndex++ ;
            leftIndex++ ;
        }
        else
        {
            arr[mainArrayIndex] = right[rightIndex];
            mainArrayIndex++ ;
            rightIndex++ ;
        }
    }

    while (rightIndex < lenRight)
    {
        arr[mainArrayIndex] = right[rightIndex];
        mainArrayIndex++ ;
        rightIndex++ ;
    }
    
    while (leftIndex < lenLeft)
    {
        arr[mainArrayIndex] = left[leftIndex];
        mainArrayIndex++ ;
        leftIndex++ ;
    }

    delete[] left;
    delete[] right;
}

void mergeSort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }
    int mid = (s + e)/2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {2, 1, 7, 6, 9, 8, 4, 5, 3};
    int size = 9;
    int s = 0;
    int e = size - 1;

    mergeSort(arr, s, e);
    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}