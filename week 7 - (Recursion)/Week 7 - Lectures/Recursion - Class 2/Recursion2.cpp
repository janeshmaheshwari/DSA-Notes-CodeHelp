#include <bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;

int ClimbStairs(int n) //(n > 0) at n = 0 --> ans = 1 (wrong answer)
{                      //but input starts from (value - 1) onwards
    if (n == 0)
    {
        return 1;
    }
    if (n == 1)
    {
        return 1;
    }
    
    int ans = ClimbStairs(n-1) + ClimbStairs(n-2);
    return ans;
}

void PrintArray(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    }
    
    cout << arr[index] << " ";
    PrintArray(arr, size, ++index);
}

bool FindTarget(int arr[], int size, int target, int index)
{
    if (index >= size)
    {
        return false;
    }
    if (arr[index] == target)
    {
        return true;
    }

    return FindTarget(arr, size, target, ++index);
}

void FindMin(int arr[], int size, int index, int &mini)
{
    if (index >= size)
    {
        return;
    }
    
    mini = min(mini, arr[index]);
    FindMin(arr, size, ++index, mini);
}

void EvenVector(int arr[], int size, int index, vector<int> &ans)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index]%2 == 0)
    {
        ans.push_back(arr[index]);
    }
    
    EvenVector(arr, size, ++index, ans);
}

void DoubleTheArray(int arr[], int size, int index)
{
    if (index >= size)
    {
        return;
    }
    
    arr[index] *= 2;
    DoubleTheArray(arr, size, ++index);
}

void FindMax(int arr[], int size, int index, int &maxx)
{
    if (index >= size)
    {
        return;
    }
    
    maxx = max(maxx, arr[index]);
    FindMax(arr, size, ++index, maxx);
}

int FindInArray(int arr[], int size, int index, int target)
{
    if (index >= size)
    {
        return -1;
    }
    if (arr[index] == target)
    {
        return index;
    }
    
    return FindInArray(arr, size, ++index, target);
}

void PrintAllOccurences(int arr[], int size, int index, int target)
{
    if (index >= size)
    {
        return;
    }
    if (arr[index] == target)
    {
        cout << index << " ";
    }
    
    return PrintAllOccurences(arr, size, ++index, target);
}

vector<int> storeAllOccurences(int arr[], int size, int index, int target, vector<int> &ans)
{
    if (index >= size)
    {
        return ans;
    }
    if (arr[index] == target)
    {
        ans.push_back(index);
    }
    
    return storeAllOccurences(arr, size, ++index, target, ans);
}

vector<int> Int_Vector(int n, vector<int> &ans)
{
    if (n == 0)
    {
        return ans;
    }

    int last_digit = n%10;
    Int_Vector(n/10, ans);
    ans.push_back(last_digit);
};

int main()
{
    // cout << ClimbStairs(5) << endl;
    
    int arr[] = {2, 3, 4, 5, 6, 5, 6, 3, 5, 2, 5};
    int arr_size = 11;
    int arr_index = 0;
    int arr_target = 5;
    int mini = INT32_MAX;
    int maxx = INT32_MIN;
    vector<int> v;

    // PrintArray(arr, arr_size, arr_index);

    // cout << FindTarget(arr, arr_size, arr_target, arr_index) << endl;

    // FindMin(arr, arr_size, arr_index, mini);
    // cout << mini << endl;

    // FindMax(arr, arr_size, arr_index, maxx);
    // cout << maxx << endl;

    // EvenVector(arr, arr_size, arr_index, v);
    // for (int num : v)
    // {
    //     cout << num << " ";
    // }

    // DoubleTheArray(arr, arr_size, arr_index);
    // for (int num : arr)
    // {
    //     cout << num << " ";
    // }

    // cout << FindInArray(arr, arr_size, arr_index, arr_target) << endl;

    // PrintAllOccurences(arr, arr_size, arr_index, arr_target);

    // storeAllOccurences(arr, arr_size, arr_index, arr_target, v);
    // for (int num : v)
    // {
    //     cout << num << " ";
    // }

    Int_Vector(1234, v);
    for (int num : v)
    {
        cout << num << endl;
    }

    return 0;
}