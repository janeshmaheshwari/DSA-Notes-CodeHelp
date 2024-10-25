#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

void Print1DVector(vector<int> v)
{
    cout << "Printing 1D Vector :-" << endl;
    for(auto it:v)
    {
        cout << it << " ";
    }
    cout << endl;
}

void Print2DVector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

vector<int> ShiftNegativeOneSideLoop(vector<int>& nums)
{
    int i = 0;
    int size = nums.size();
    for (int index = 0; index < size; index++)
    {
        if (nums[index] < 0)
        {
            swap(nums[index], nums[i]);
            i++ ;
        }
    }
    return nums;
}

vector<int> SortColors(vector<int>& nums)
{
    int size = nums.size();
    int index = 0;
    int left = 0;
    int right = size - 1;

    while (index <= right)
    {
        if (nums[index] == 0)
        {
            swap(nums[index], nums[left]);
            left++ ;
            index++ ;
        }
        else if (nums[index] == 2)
        {
            swap(nums[index], nums[right]);
            right-- ;
        }
        else
        {
            index++ ;
        }
    }
    return nums;  
}

//Rotate array (Type-II) :-
//Modulus with Extra Space
vector<int> RotateLinearModulus(vector<int>& nums, int k)
{
    int size = nums.size();
    vector<int> ans(size);

    for (int index = 0; index < size; index++)
    {
        int new_index = (index + k) % size;
        ans[new_index] = nums[index];
    }
    nums = ans;
    return nums;
}

//Rotate array (Type-III) :-
//Reversal Method
vector<int> RotateLinearReversal(vector<int>&nums, int k)
{
    k = k % nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin()+k, nums.end());
    return nums;
}

int MissingNumber(vector<int> nums)
{
    int size = nums.size();
    int TotalSum = ((size)*(size+1)/2);
    int ActualSum = 0;

    for (int i = 0; i < size; i++)
    {
        ActualSum += nums[i];
    }
    return (TotalSum - ActualSum);
}

int MissingNumberXOR(vector<int> nums)
{
    int size = nums.size();
    int ans = 0;
    for (int i = 0; i <= size; i++)
    {
        ans = ans^i;
    }
    for (int i = 0; i < size; i++)
    {
        ans = ans^nums[i];
    }
    return ans;
}

vector<int> RearrangeArray(vector<int> nums) //HW
{
    int high = 0;
    int low = 1;
    int size = nums.size();
    while (high < size)
    {
        while (nums[high] > 0)
        {
            high = high + 2 ;
        }
        while (nums[low] < 0)
        {
            low = low + 2;
        }
        swap(nums[high], nums[low]);
    }
    return nums;
}

vector<int> RowAndMaximumOnes(vector <vector<int>>& mat)
{
    vector<int> v;
    int MaxSum = -1;
    int RowIndex = 0;
    for (int i = 0; i < mat.size(); i++)
    {
        int RowSum = 0;
        for (int j = 0; j < mat[i].size(); j++)
        {
            RowSum += mat[i][j];
        }
        if (RowSum > MaxSum)
        {
            MaxSum = RowSum;
            RowIndex = i;
        }
    }
    v.push_back(RowIndex);
    v.push_back(MaxSum);

    return v;
}

vector<vector<int>> RotateMatrix(vector<vector<int>>& matrix)
{
//  Transpose
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = i + 1; j < matrix[i].size(); j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

//  Reverse --> Implement By own without using Function
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    
    return matrix;
}

int main()
{
    vector<int> arr = {23, -7, 12, -10, -11, 40, 60};
    // Print1DVector(ShiftNegativeOneSideLoop(arr));

    vector<int> brr = {1, 0, 2, 2, 1, 0, 1, 0};
    // Print1DVector(SortColors(brr));

    vector<int> crr = {10, 20, 30, 40, 50, 60};
    int rotate = 4;
    // Print1DVector(RotateLinearModulus(crr, rotate));
    // Print1DVector(RotateLinearReversal(crr, rotate));

    vector<int> drr = {1, 7, 3, 2, 5, 6, 8, 0};
    // cout << MissingNumber(drr);
    // cout << MissingNumberXOR(drr);

    vector<int> err = {3, 1, -2, -5, 2, -4};
    // Print1DVector(RearrangeArray(err));

    vector<vector<int>> frr = {{1, 0, 0}, {1, 1, 0}, {1, 1, 1}, {0, 1, 0}};
    // Print1DVector(RowAndMaximumOnes(frr));

    vector<vector<int>> grr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // Print2DVector(RotateMatrix(grr));

    return 0;
} 