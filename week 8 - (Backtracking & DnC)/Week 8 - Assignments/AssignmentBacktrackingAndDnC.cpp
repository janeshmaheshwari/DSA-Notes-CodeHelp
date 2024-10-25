#include <iostream>
#include <vector>
using namespace std;

long countInversion1(vector<int> arr)
{
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            count = arr[i] > arr[j] ? count + 1 : count;
        }
    }
    return count; 
}

void mergesort(vector<int>& arr, vector<int>& temp, int start, int end)
{
    if (start >= end) return;
    int mid = (start + end)/2;
}

long countInversion2(vector<int> arr)
{
    long count = 0;
    vector<int> temp(arr.size(), 0);
    mergesort(arr, temp, 0, arr.size()-1);

}

int main()
{
    

    return 0;
}