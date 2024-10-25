#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

void PrintVector(vector<int> v)
{
    cout << "Printing 1D Vector :-" << endl;
    for(auto it:v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int bs_KdiffPairs(vector<int>& nums, int start, int x)
{
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end)/2;
        if (nums[mid] == x)
        {
            return mid;
        }
        else if (x > nums[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

int KdiffPairs(vector<int> nums, int k)
{
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;
    
    // int i = 0, j = 1;
    // int diff;
    // while (j < nums.size())
    // {
    //     if (i == j)
    //     {
    //         j++ ;
    //     }
    //     diff = nums[j] - nums[i];
    //     if (diff == k)
    //     {
    //         ans.insert({nums[i], nums[j]});
    //         i++, j++;
    //     }
    //     else if (diff > k)
    //     {
    //         i++ ;
    //     }
    //     else
    //     {
    //         j++ ;
    //     }
    // }

    for (int i = 0; i < nums.size(); i++)
    {
        if (bs_KdiffPairs(nums, i+1, nums[i] + k != -1))
        {
            ans.insert({nums[i], nums[i] + k});
        }
    }

    return ans.size();
}

vector<int> bs_findClosestElement(vector<int>& arr, int k, int x)
{
    int s = 0, e = arr.size()-1;
    int ans = e;
    int mid;
    while (s <= e)
    {
        mid = (s + e)/2;
        if (arr[mid] >= x)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < x)
        {
            s = mid + 1;
        }
        else
        {
            e =  mid - 1;
        }
    }
    int h = ans; //ans = lowerbound
    int l = h - 1;
    while (k--)
    {
        if (l < 0)
        {
            h++ ;
        }
        else if (h >= arr.size())
        {
            l-- ;
        }
        else if (x - arr[l] > arr[h] - x )
        {
            h++ ;
        }
        else
        {
            l-- ;
        }
    }
    return vector<int> (arr.begin() + l + 1, arr.begin() + h); 
}

vector<int> findClosestElement(vector<int>& arr, int k, int x)
{
    vector<int> ans;
    int l = 0;
    int h = arr.size() - 1;
    while (h - l >= k)
    {
        if (x - arr[l] > arr[h] - x)
        {
            l++ ;
        }
        else
        {
            h-- ;
        }
    }
    return vector<int> (arr.begin() + l, arr.begin() + h + 1);
}

int expSearch(vector<int>& a, int x)
{
    //Exponential Search
    int n = a.size();
    if (a[0] == x)
    {
        return 0;
    }
    int i = 1;
    while (i<n && a[i] <= x)
    {
        i*=2; //OR i = i << 1;
    }

    //Binary Search (a, i/2, min(i, n-1), x);
    int s = i/2;
    int e = min(i, n-1);
    int mid;

    while (s <= e)
    {
        mid = (s + e)/2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (x > a[mid])
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

bool isPossibleSol1(int A[], int N, int M, int sol)
{
    int pageSum = 0;
    int c = 1;
    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol)
        {
            return false;
        }
        else if (pageSum + A[i] > sol)
        {
            c++ ;
            pageSum = A[i];
            if (c > M)
            {
                return false;
            }
        }
        else
        {
            pageSum += A[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    if (M > N)
    {
        return -1;
    }

    int s = 0;
    int e = accumulate(A, A+N, 0); //SUM of pages
    int ans = -1;
    int mid;

    while (s <= e)
    {
        mid = (s + e) >> 1;

        if (isPossibleSol1(A, N, M, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

bool isPossibleSol2(int arr[], int n, int k, long long mid)
{
    long long timeSum = 0;
    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (arr[i] + timeSum > mid)
        {
            c++ ;
            timeSum = arr[i];
            if (c > k)
            {
                return false;
            }
        }
        else
        {
            timeSum += arr[i];
        }
    }
    return true;
}

long long minTime(int arr[], int n, int k)
{
    long long s = 0;
    long long e = 0;
    for (int i = 0; i < n; i++)
    {
        e += arr[i];
    }
    long long ans = -1;
    long long mid;

    while (s <= e)
    {
        mid = s + (e - s)/2;
        if (isPossibleSol2(arr, n, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

bool isPossibleSol3(vector<int> &stalls, int k, int mid)
{
    int cow = 1;
    int pos = stalls[0];

    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - pos >= mid)
        {
            cow++ ;
            pos = stalls[i];
        }
        if (cow == k)
        {
            return true;
        }
    }
    return false;
}

int AgressiveCow(int k, vector<int> &stalls)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    int mid;

    while (s <= e)
    {
        mid = (s + e) >> 1;
        if (isPossibleSol3(stalls, k, mid))
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

bool isPossibleSol4(vector<int> Trees, int M, int mid)
{
    long long int WoodCollected = 0;
    for (int i = 0; i < Trees.size(); i++)
    {
        if (Trees[i] > mid)
        {
           WoodCollected += Trees[i] - mid;
        }
    }
    return WoodCollected >= M;
}

int CutTrees(int M, vector<int>& Trees)
{
    int s = 0;
    int e = *max_element(Trees.begin(), Trees.end());
    int ans = -1;
    int mid;

    while (s <= e)
    {
        mid = s + (e - s)/2;
        if (isPossibleSol4(Trees, M, mid))
        {
            ans = mid;
            s = mid + 1;//For Max Height of Trees 
                        //and Least cut of Trees
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

bool isPossibleToCook(vector<int>& cooksRanks, int nP, int mid) {
    int currP = 0; // Current number of parathas cooked
    for (int i = 0; i < cooksRanks.size(); i++) {
        int R = cooksRanks[i];
        int j = 1; // Paratha counter for the current cook
        int timeTaken = 0;

        while (timeTaken + j * R <= mid) {
            currP++;
            timeTaken += j * R;
            j++;
            if (currP >= nP) {
                return true;
            }
        }
    }
    return currP >= nP;
}

int minTimeToCompleteOrder(vector<int>& cooksRanks, int nP) {
    int s = 0;
    int e = *max_element(cooksRanks.begin(), cooksRanks.end()) * ((nP * (nP + 1)) / 2); // Maximum possible time
    int ans = -1;

    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (isPossibleToCook(cooksRanks, nP, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 1, 1, 1};
    int arr_diff = 0;
    // cout << KdiffPairs(arr, arr_diff) << endl;

    vector<int> brr = {12, 16, 22, 30, 35, 39, 42, 45, 48, 50, 53, 55, 56};
    int brr_k = 4;
    int brr_x = 35;
    // PrintVector(findClosestElement(brr, brr_k, brr_x));
    // PrintVector(bs_findClosestElement(brr, brr_k, brr_x));

    vector<int> crr = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int crr_x = 56;
    // cout << expSearch(crr, crr_x) << endl;

    int drr[4] = {12, 34, 67, 90};
    int drr_n = 4; //Books
    int drr_m = 2; //Students
    // cout << findPages(drr, N, M) << endl;

    int err[5] = {5, 10, 30, 20, 15};
    int err_n = 5; //Board
    int err_k = 3; //Painters
    // cout << minTime(err, n, k) << endl;

    vector<int> frr = {10, 1, 2, 7, 5};
    int frr_k = 3;
    // cout << AgressiveCow(frr_k, frr) << endl;

    int N = 4; //Number of Maximum Trees that can be cut
    int M = 7; //The Minimum amount of wood to be cut
    vector<int> Trees = {20, 15, 10, 17};
    // cout << CutTrees(M, Trees) << endl;

    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int nP, l;
        cin >> nP >> l;
        vector<int> cooksRanks(l);

        for (int i = 0; i < l; i++) {
            cin >> cooksRanks[i];
        }

        cout << minTimeToCompleteOrder(cooksRanks, nP) << endl;
    }
/*
3 
10 
4 1 2 3 4 
8 
1 1 
8 
8 1 1 1 1 1 1 1 1

Output :- 12 36 1
*/
    return 0;
}