#include <iostream>
#include <vector>
using namespace std;

int solveRob(vector<int>& nums, int index, int size)
{
    // Base Case
    if (index >= size) return 0;
    
    // Chori at ith index
    int opt1 = nums[index] + solveRob(nums, index+2, size);
    int opt2 = 0 + solveRob(nums, index+1, size);

    // Chori not al ith index
    int finalAns = max(opt1, opt2);
    return finalAns;
}

int rob(vector<int>& nums)
{
    int n = nums.size();
    if (n == 1) return nums[0];
    
    int opt1 = solveRob(nums, 0, n-1);
    int opt2 = solveRob(nums, 1, n);

    int ans = max(opt1, opt2);
    return ans;
}

int CountDerangements(int n)
{
    //Base
    if (n == 1) return 0;
    if (n == 2) return 1;
    
    int ans = (n-1) * (CountDerangements(n-1) + CountDerangements(n-2));
    return ans;
}

int getPaintWays(int n, int k)
{
    // Base Case
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return k + k*(k-1); //Same + Different
    }
    
    // k-1 * (Same + Different)
    int ans = (k-1) * (getPaintWays(n-1, k) + getPaintWays(n-2, k));
    return ans;
}

int solveMinDistance(string& word1, string& word2, int i, int j)
{
    // Base Case
    if (i >= word1.length())
    {
        // word1 waali string end ho gayi
        // yani word1 length smaller than word 2
        return word2.length() - j;
    }
    if (j >= word2.length())
    {
        // word1 waali string end ho gayi
        // yani word1 length smaller than word 2
        return word1.length() - i;
    }
    
    int ans = 0;

    if (word1[i] == word2[j])
    {
        // Match kar gaya
        ans = 0 + solveMinDistance(word1, word2, i+1, j+1);
    }
    else
    {
        // Not Match, Operation perform karo

        // Insert
        int opt1 = 1 + solveMinDistance(word1, word2, i, j+1);

        // Remove
        int opt2 = 1 + solveMinDistance(word1, word2, i+1, j);

        // Replece
        int opt3 = 1 + solveMinDistance(word1, word2, i+1, j+1);

        ans = min(opt1, min(opt2, opt3));
    }
    return ans;
}

int minDistance(string& word1, string& word2)
{
    // Convert Word1 to Word2 by (Insert, Delete, Replace)
    int i = 0;
    int j = 0;
    int ans = solveMinDistance(word1, word2, i, j);
    return ans;
}

int solve(vector<vector<char>>& matrix, int i, int j, int row, int col, int& maxi)
{
    if (i >= row || j >= col) return 0;
    
    // Explore all 3 Directions
    int right = solve(matrix, i, j+1, row, col, maxi);
    int diagonal = solve(matrix, i+1, j+1, row, col, maxi);
    int down = solve(matrix, i+1, j, row, col, maxi);

    if (matrix[i][j] == '1')
    {
        int ans = 1 + min(right, min(diagonal, down));
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}

int maximalSquare(vector<vector<char>>& matrix)
{
    int i = 0;
    int j = 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int maxi = 0;
    int ans = solve(matrix, i, j, row, col, maxi);
    return maxi * maxi;
}

int main()
{
    vector<int> v1 = {1, 9, 3, 1, 6};
    // cout << rob(v1) << endl;

    // cout << CountDerangements(4) << endl;

    // cout << getPaintWays(2, 3);

    string a = "horse";
    string b = "ros";
    // cout << minDistance(a, b) << endl;

    vector<vector<char>> v2
    {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };
    // cout << maximalSquare(v2) << endl;

    return 0;
}