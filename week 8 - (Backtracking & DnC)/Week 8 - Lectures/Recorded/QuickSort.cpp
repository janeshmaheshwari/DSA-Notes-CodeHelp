#include <iostream>
using namespace std;

void QuickSort(int a[], int s, int e)
{
    if (s >= e) return;
    int pivot = e;
    int i = s - 1;
    int j = s;

    while (j < pivot)
    {
        if (a[j] < a[pivot])
        {
            ++i;
            swap(a[i], a[j]);
        }
        ++j;
    }
    ++i;
    swap(a[i], a[pivot]);
    QuickSort(a, s, i - 1);
    QuickSort(a, i + 1, e);
}

int main()
{
    int arr[8] = {7, 2, 1, 8, 6, 3, 5, 4};
    QuickSort(arr, 0, 7);

    for (int i : arr)
    {
        cout << i << " ";
    }

    return 0;
}