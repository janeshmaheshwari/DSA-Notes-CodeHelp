#include <iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#include<set>
#include<vector>
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

void PrintPairs(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    { 
        for (int j = i + 1; j < size; j++)
        {
            cout << "{" << arr[i] << ", " << arr[j] << "}" << endl;
        }
    }
}

bool PairSumByTwoLoopsX(int arr[], int size, int x) //Two Sum by 2 Loops => O(n^2) 
{   
    for (int i = 0; i < size; i++)
    { 
        for (int j = i+1; j < size; j++)
        {
            if (arr[i] + arr[j] == x)
                return true;
        }
    }
    return false;
}

bool PairSumTwoPointersByX(int arr[], int size, int x) // Sorted Array Required => O(n) 
{   
    int Low = 0;
    int High = size - 1;
    int Sum = arr[Low] + arr[High];

    while (Low < High)
    {
        if (Sum == x)
        {
            return true;
        }
        else if (Sum > x)
        {
            High-- ;
        }
        else
        {
            Low-- ;
        }    
    }
    return false;
}

int PivotIndex(vector<int> nums)
{
    vector<int>lsum(nums.size(), 0);
    vector<int>rsum(nums.size(), 0);

    for (int i = 1; i < nums.size(); i++)
    {
        lsum[i] = lsum[i-1] + nums[i-1];
    }
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        rsum[i] = rsum[i+1] + nums[i+1];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (lsum[i] == rsum[i])
        {
            return i;
        }
        
    }
    return -1;
}
/*
Sort Coloers --> Arrays Extra Class
Missing Number --> Arrays Extra Class
(1) Move All Negative Number to One Side by Loop --> Arrays Extra Class
    --> No Sequence is Lost !!!
(2) Move All Negative Number to One Side by Dutch Method (Two Pointers)
    --> Sequence is Lost !!!
*/
vector<int> ShiftNegativeOneSideTwoPonters(vector<int>& nums)
{
    int l = 0, h = nums.size() - 1;
    while (l < h)
    {
        if (nums[l] < 0)
        {
            l++ ;
        }
        else if (nums[h] > 0)
        {
            h-- ;
        }
        else
        {
            swap(nums[l], nums[h]);
        }
    }
    return nums;
}

int MissingElement1(vector<int>& nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int index = abs(nums[i]);
        if (nums[index - 1] > 0)
        {
            nums[index - 1] = -1 * nums[index - 1];
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] > 0)
        {
            return i+1;
        }
    }
}

int MissingElement2(vector<int>& nums)
{
    int i = 0;
    while (i < nums.size())
    {
        int index = nums[i] - 1;
        if (nums[i] != nums[index])
        {
            swap(nums[i], nums[index]);
        }
        else
        {
            i++ ;
        }
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i+1)
        {
            return i+1;
        }
    }
}

int FirstRepeated(vector<int> nums)
{
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++)
    {
        hash[nums[i]]++ ;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (hash[nums[i]] > 1)
        {
            return i+1;
        } 
    }
    return -1;
}

vector<int> ComElem3SortArray(vector<int> A, vector<int> B, vector<int> C)
{
    vector<int> ans;
    set<int> st;
    int i, j, k;
    i = j = k = 0;

    while (i < A.size() && j < B.size() && k < C.size())
    {
        if (A[i] == B[j] && B[j] == C[k])
        {
            st.insert(A[i]);
            i++; j++; k++;
        }
        else if (A[i] < B[j])
        {
            i++ ;
        }
        else if (B[j] < C[k])
        {
            j++ ;
        }
        else
        {
            k++ ;
        }
    }
    for (auto i:st)
    {
        ans.push_back(i);
    }
    return ans;
}

vector<int> WavePrintMatrix(vector<vector<int>> v)
{
    vector<int> ans;
    for (int j = 0; j < v[0].size(); j++)
    {
        if (j%2 == 0)
        {
            for (int i = 0; i < v.size(); i++)
            {
                ans.push_back(v[i][j]);
            }
        }
        else
        {
            for (int i = v.size() - 1; i >= 0; i--)
            {
                ans.push_back(v[i][j]);
            }
        }
    }
    return ans;
}

vector<int> SprintPrintMatrix(vector<vector<int>> v)
{
    vector<int> ans;
    int m = v.size();
    int n = v[0].size();
    int TotalElements = m*n;
    
    int StartingRow = 0;
    int EndingCol = n-1;
    int EndingRow = m-1;
    int StartingCol = 0;

    int Elements = 0;
    while (Elements < TotalElements)
    {
        for (int i = StartingCol; i <= EndingCol && Elements < TotalElements; i++)
        {
            ans.push_back(v[StartingRow][i]);
            Elements++ ;
            
        }
        StartingRow++ ;

        for (int i = StartingRow; i <= EndingRow && Elements < TotalElements; i++)
        {
            ans.push_back(v[i][EndingCol]);
            Elements++ ;
        }
        EndingCol-- ;

        for (int i = EndingCol; i >= StartingCol && Elements < TotalElements; i--)
        {
            ans.push_back(v[EndingRow][i]);
            Elements++ ;
        }
        EndingRow-- ;

        for (int i = EndingRow; i >= StartingRow && Elements < TotalElements; i--)
        {
            ans.push_back(v[i][StartingCol]);
            Elements++ ;
        }
        StartingCol++ ;
    }

    return ans;
}

string Calc_Sum(int *a, int n, int *b, int m)
{
    string ans;
    int carry = 0;
    int i = n-1;
    int j = m-1;

    while (i>=0 && j>=0)
    {
        int x = a[i] + b[j] + carry;
        int digit = x%10;
        ans.push_back(digit + '0');
        carry = x/10;
        i-- ;
        j-- ;
    }
    
    while (i>=0)
    {
        int x = a[i] + carry;
        int digit = x%10;
        ans.push_back(digit + '0');
        carry = x/10;
        i-- ;
    }

    while (j>=0)
    {
        int x = b[j] + carry;
        int digit = x%10;
        ans.push_back(digit + '0');
        carry = x/10;
        j-- ;
    }

    if (carry)
    {
        ans.push_back(carry + '0');
    }

    while (ans[ans.size() - 1] == '0')
    {
        ans.pop_back();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

vector<int> FactorialLargeNum(int n)
{
    vector<int> ans;
    ans.push_back(1);
    int carry = 0;
    int x;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < ans.size(); j++)
        {
            x = ans[j]*i + carry;
            ans[j] = x%10;
            carry = x/10;
        }
        while (carry)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
        carry = 0;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int RemoveDuplicates(vector<int> v)
{
    int j = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] == v[j])
        {
           i++ ;
        }
        else
        {
            v[++j] = v[i++];
        }
    }
    return j+1;
}

double FindMaxAverage(vector<int>& nums, double k)
{
    int sum = 0;
    int i = 0;
    while (i < k)
    {
        sum += nums[i];
        i++ ;
    }
    int left = 0;
    int right = k;
    double newsum = sum;
    while (right < nums.size())
    {
        newsum += (nums[right++] - nums[left++]);
        if (newsum > sum)
        {
            sum = newsum;
        }
    }
    return sum/k;
}

int main()
{
    int arr[3] = {10, 20, 30};
    int arr_size = 3;
    int Target = 40;

    // PrintPairs(arr, arr_size);
    // cout << PairSumByTwoLoopsX(arr, arr_size, Target) << endl;
    // cout << PairSumTwoPointersByX(arr, arr_size, Target) << endl;

    vector<int> v1 = {1, 7, 3, 6, 5, 6};
    // cout  << PivotIndex(v1) << endl;

    vector<int> v2 = {23, -7, 12, -10, -11, 40, 60};
    // Print1DVector(ShiftNegativeOneSideTwoPonters(v2));

    vector<int> v3 = {1, 3, 5, 3, 4};
    // cout << MissingElement1(v3) << endl;
    // cout << MissingElement2(v3) << endl;

    vector<int> v4 = {1, 5, 3, 4, 3, 5, 6};
    // cout << FirstRepeated(v4) << endl; //1 Indexing

    vector<int> v5_1 = {1, 5, 10, 20, 40, 80};
    vector<int> v5_2 = {6, 7, 20, 80, 100};
    vector<int> v5_3 = {3, 4, 15, 20, 30, 70, 80, 120};
    // Print1DVector(ComElem3SortArray(v5_1, v5_2, v5_3));

    vector<vector<int>> v6 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // Print1DVector(WavePrintMatrix(v6));

    vector<vector<int>> v7 = {{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 28, 29, 30}};
    // Print1DVector(SprintPrintMatrix(v7));

    int a[6] = {5, 3, 1, 7, 9, 0};
    int n = 6;
    int b[7] = {0, 4, 5, 8, 3, 0, 9};
    int m = 7;
    // cout << Calc_Sum(a, n, b, m) << endl;

    // Print1DVector(FactorialLargeNum(20));

    vector<int> v8 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    // cout << RemoveDuplicates(v8) << endl;

    vector<int> v9 = {1, 12, -5, -6, 50, 3};
    cout << FindMaxAverage(v9, 4) << endl;

    return 0;
}