#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& v, vector<int>& temp, int start, int mid, int end)
{
    int i = start, j = mid + 1;

    // 1st array = start -> end
    // 2nd array = mid+1 -> end
    // merged array = start ->end

    int k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
        }
    }
    
    // Handle Remaining elements in case of diff array size

    while (i <= mid)
    {
        temp[k++] = v[i++];
    }
    while (j <= end)
    {
        temp[k++] = v[j++];
    }

    // Let's copy merged data
    
    while (start <= end)
    {
        v[start] = temp[start];
        start++;
    }
}

void mergeSort(vector<int>& v, vector<int>& temp, int start, int end)
{
    if (start >= end) return;
    
    int mid = (start + end) / 2;

    // divide
    mergeSort(v, temp, start, mid);
    mergeSort(v, temp, mid + 1, end);
    
    //conqour
    merge(v, temp, start, mid, end);
}

vector<int> sortArray(vector<int>& nums)
{
    vector<int> temp(nums.size(), 0);
    mergeSort(nums, temp, 0, nums.size() - 1);
    return nums;
}

int main()
{
    vector<int> v = {5, 1, 1, 2, 0, 0};

    // sortArray(v);
    // for (int i : v)
    // {
    //     cout << i << " ";
    // }


//(1) Allocate int on heap (using new)
    int *intptr1 = new int(5);
    // intptr1 variable on stack
    // saving address of (5) on heap


//(2) Allocate int on heap (using malloc)
    void *ptr2 = malloc(4);
    // ptr2 variable on stack
    // taking 4 bytes of space on heap
    // intializing it as void data type

    int *intptr2 = (int*) ptr2;
    // intptr2 variable on stack
    // implicit type casting pointer ptr2 = void* -> int*

    *intptr2 = 5;
    // saving address of (5) on heap

    // OR syntax can be
    int *intptr3 = (int*) malloc(4);
    *intptr3 = 5;


//=> PRINTING (1) & (2)
    cout << "*intptr1 = " << *intptr1 << ", *intptr2 = "
    << *intptr2 << ", *intptr3 = " << *intptr3 << endl;

    delete intptr1;
    free(intptr2);
    free(intptr3);


//(3) Allocate 1D array on heap (using new)
    int *arr1D = new int[5];


//(4) Allocate 1D array on heap (using malloc)
    int*brr1D = (int*)malloc(5 * sizeof(int)); // (5 * 4) 20 bytes allocated


//=> PRINTING (3) & (4)
    for (int i = 0; i < 5; i++)
    {
        arr1D[i] = brr1D[i] = i;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << "(" << i << ")" << " => arr1D = " <<
        arr1D[i] << ", brr1D = " << brr1D[i] << endl;
    }
    
    delete[] arr1D;
    free(brr1D);


//(5) Allocate 2D array on heap (using new)
    int rows = 3, cols = 3;

    int **arr2D = new int*[rows];

    for (int i = 0; i < rows; i++)
    {
        arr2D[i] = new int[cols];
    }


//(6) Allocate 2D array on heap (using malloc)
    int **brr2D = (int**)malloc(sizeof(int*) * rows); // (8 * 5) 40 bytes allocated

    for (int i = 0; i < rows; i++)
    {
        brr2D[i] = (int *)malloc(sizeof(int) * cols);
    }
    

//=> PRINTING (5) & (6)
    int count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr2D[i][j] = brr2D[i][j] = count++;
        }
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "(" << i << ", " << j << ") => arr2D[i][j] = " <<
            arr2D[i][j] << ", brr2D[i][j] = " << brr2D[i][j] << endl;
        }
    }

    for (int i = 0; i < rows; i++) // Deleting all rows
    {
        delete[] arr2D[i]; 
        free(brr2D[i]);
    }

    // Deleting column of all sequencial rows
    delete[] arr2D; 
    free(brr2D);

    return 0;
}