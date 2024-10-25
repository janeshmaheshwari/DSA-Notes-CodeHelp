#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool CheckSorted(int arr[], int size, int index) //Index = 1
{
    if (index >= size)
    {
        return true;
    }
    if (arr[index] < arr[index-1])
    {
        return false;
    }
    return CheckSorted(arr, size, ++index);
}

int BinarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end-start)/2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] < target)
    {
        return BinarySearch(arr, mid + 1, end, target);
    }
    else
    {
        return BinarySearch(arr, start, mid - 1, target);
    }
}

void FindSubSequences1(string s, string output, int index, vector<string> &ans)
{
    if (index >= s.length())
    {
        cout << "-> " << output << endl;
        ans.push_back(output);
        return;
    }
    char ch = s[index];

    //Exclude
    FindSubSequences1(s, output, index+1, ans);

    //Include
    output.push_back(ch);
    FindSubSequences1(s, output, index+1, ans);

/*  Include First than Exclude :-  

    //Include
    output.push_back(ch);
    FindSubSequences1(s, output, index+1);

    //Exclude
    output.pop_back();
    FindSubSequences1(s, output, index+1);
*/   
}

void FindSubSequences2(string& s)
{
    int num_subs = pow(2, s.size());

    for (int i = 0; i < num_subs; i++)
    { 
        string out;
        int num = i;

        //Binary to Sub-Sequences
        int j = 0;
        while (num)
        {
            int b = (num & 1);

            cout << b << " "; //Convert num to Binary

            if (b)
            {
                out.push_back(s[j]);
            }
            j++ ;
            num >>= 1;
        }
        cout << out << endl;
    }
}

int MaximiseTheCuts(int n, int x, int y, int z)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT32_MIN;
    }
    
    int opt1 = 1 + MaximiseTheCuts(n-x, x, y, z);
    int opt2 = 1 + MaximiseTheCuts(n-y, x, y, z);
    int opt3 = 1 + MaximiseTheCuts(n-z, x, y, z);

    int finalAns = max(opt1, max(opt2, opt3));
    return finalAns;
}

int SolveCoin(vector<int> &coins, int amount)
{
    if (amount == 0)
    {
        return 0;
    }
    if (amount < 0)
    {
        return INT32_MAX;
    }
    
    
    int mini = INT32_MAX;
    int ans = INT32_MAX;

    for (int i = 0; i < coins.size(); i++)
    {
        int coin = coins[i];

        if (coin <= amount)
        {
            int recAns = SolveCoin(coins, amount - coin);
            if (recAns != INT32_MAX)
            {
                ans = 1 + recAns;
                mini = min(mini, ans);
            }
        }
    }
    return mini;
}

int coinChange(vector<int> &coins, int amount)
{
    int ans = SolveCoin(coins, amount);

    if (ans == INT32_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

int SolveRob(vector<int>& nums, int size, int index)
{
    if (index >= size)
    {
        return 0;
    }

    //Robbing on the i-th Index
    int opt1 = nums[index] + SolveRob(nums, size, index+2);

    //Not Robbing on i-th Index
    int opt2 = 0 + SolveRob(nums, size, index+1);

    int finalAns = max(opt1, opt2);
    return finalAns;
}

int Rob(vector<int>& nums)
{
    int size = nums.size();
    int index = 0;
    int ans = SolveRob(nums, size, index);
    return ans;
}

int main()
{
    int arr[] = {10, 20, 30, 50, 60, 70};
    int arr_size = 6;
    int arr_index = 1;
    // cout << CheckSorted(arr, arr_size, arr_index) << endl;

    int arr_start = 0;
    int arr_end = arr_size - 1;
    int arr_target = 70;
    // cout << BinarySearch(arr, arr_start, arr_end, arr_target) << endl;

    string s = "abc";
    string output = "";
    int index = 0;
    vector<string> ans;
    // FindSubSequences1(s, output, index, ans);
 
    // cout << endl << "Printing Vector :-" << endl; 
    // for (string str : ans) //(auto str : ans)
    // {
    //     cout << "=> "<< str << endl;
    // }

    // FindSubSequences2(s);

    // cout << MaximiseTheCuts(4, 2, 1, 1) << endl;

    vector<int> coins = {1, 2, 5};
    int amount = 11;
    // cout << coinChange(coins, amount) << endl;

    vector<int> nums1 = {1, 2, 3, 1}; //4
    // cout << Rob(nums1) << endl;
    vector<int> nums2 = {2, 7, 9, 3, 1}; //12
    // cout << Rob(nums2) << endl;

    return 0;
}