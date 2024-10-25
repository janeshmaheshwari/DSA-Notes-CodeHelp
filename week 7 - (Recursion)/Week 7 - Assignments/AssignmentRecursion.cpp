#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
using namespace std;

//Searching From Left to Right
int LastOccLTR(string &str, char ch, int i, int &ans)
{
    if (i >= str.size())
    {
        return ans;
    }
    else if (str[i] == ch)
    {
        ans = i;
    }
    LastOccLTR(str, ch, ++i, ans);
}

//Searching From Right to Left
int LastOccRTL(string &str, char ch, int i, int &ans)
{
    if (i < 0)
    {
        return ans;
    }
    if (str[i] == ch)
    {
        ans = i;
        return ans;
    }
    LastOccRTL(str, ch, --i, ans);
}

void ReverseString(string& str, int s, int e)
{
    if (s >= e)
    {
        return;
    }
    swap(str[s], str[e]);
    ReverseString(str, s+1, e-1);
}

void addRE(string& num1, int p1, string& num2, int p2, string& ans, int carry = 0)
{
    //Base case
    if (p1 < 0 && p2 < 0)
    {
        if (carry != 0)
        {
            ans.push_back(carry + '0');
        }
        return;
    }

    //Ek case solve (agar index 0 se kam hua to int 0['0'-'0'])
    int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
    int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
    int sum = n1 + n2 + carry;
    int digit = sum%10;
    carry = sum/10;
    ans.push_back(digit + '0');

    //RE
    addRE(num1, p1 - 1, num2, p2 - 1, ans, carry);
}

string addString(string num1, string num2)
{
    string ans;
    addRE(num1, num1.size() - 1, num2, num2.size() - 1, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

bool CheckPalindrome(int s, int e, string& str)
{
    if (s >= e)
    {
        return true;
    }
    if (str[s] != str[e])
    {
        return false;
    }
    CheckPalindrome(++s, --e, str);
}

bool PalindromeRE(string str)
{
    return CheckPalindrome(0, str.length(), str);
}

void printSubarray_util(vector<int>& nums, int start, int end)
{
    if (end == nums.size())
    {
        return;
    }
    
    for (int i = start; i <= end; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    printSubarray_util(nums, start, end+1);
}

void printSubarray(vector<int>& nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        int end = start;
        printSubarray_util(nums, start, end);
    }
}

void RemoveOCC(string &s, string &part)
{
    int found = s.find(part);
    if (found != string::npos)
    {
        //Part string has been located
        //Please remove it
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;

        RemoveOCC(s, part);
    }
    else
    {
        //Base case
        //All Occurences of part has been removed from s
        return;
    }
}

string RemoveOccurences(string s, string part)
{
    RemoveOCC(s, part);
    return s;
}

void maxProfitFinder(vector<int>& prices, int i, int& minPrice, int& maxProfit)
{
    //Base Case
    if (i == prices.size()) return;
    
    //Sol for 1 Case
    if (prices[i] < minPrice) minPrice = prices[i];
    int todaysProfit = prices[i] - minPrice;
    if (todaysProfit > maxProfit) maxProfit = todaysProfit;
    
    //RE
    maxProfitFinder(prices, i + 1, minPrice, maxProfit);
}

int maxProfit(vector<int>& prices)
{
    int minPrice = INT32_MAX;
    int maxProfit = INT32_MIN;
    maxProfitFinder(prices, 0, minPrice, maxProfit);
    return maxProfit;
}

vector<pair<int, string>> mp = 
{
    {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"},
    {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"},
    {60, "Sixty"} , {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"},
    {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"},
    {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"},
    {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"},
    {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}
};

string numberToWords(int num)
{
    if (num == 0)
    {
        return "Zero";
    }
    
    for (auto it : mp)
    {
        if (num >= it.first)
        {
            string a = "";
            if (num >= 100)
            {
                a = numberToWords(num / it.first) + " ";
            }
            string b = it.second;

            string c = "";
            if (num % it.first != 0)
            {
                c = " " + numberToWords(num % it.first);
            }
            return a + b + c;
        }
    }
    return "";
}

bool isMatchHelper(string &s, int si, string &p, int pi)
{
    //base
    if (si == s.size() && pi == p.size())
    {
        return true;
    }
    
    if (si == s.size() && pi < p.size())
    {
        while (pi < p.size())
        {
            if (p[pi] != '*') return false;
            pi++;
        }
        return true;
    }
    
    //Single Char Matching
    if (s[si] == p[pi] || '?' == p[pi])
    {
        return isMatchHelper(s, si+1, p, pi+1);
    }
    
    if (p[pi]== '*')
    {
        //Treat '*' as Empty or null
        bool caseA = isMatchHelper(s, si, p, pi+1);

        //Let '*' consume ine char
        bool caseB = isMatchHelper(s, si+1, p, pi);

        return caseA || caseB;
    }

    //char Doesn't match
    return false;
}

bool isMatch(string s, string p)
{
    int si = 0;
    int pi = 0;

    return isMatchHelper(s, si, p, pi);
}

int numRollsToTarget(int n, int k, int target)
{
/*
    n = number of dice
    k = number of faces
*/
    if (n == 0 && target == 0) return 1;
    if ((n == 0 && target) || (n && target == 0)) return 0;
    
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += numRollsToTarget(n - 1, k, target - i);
    }
    return ans;
}

int numSquareHelper(int n)
{
    // Base
    if (n == 0) return 1;
    if (n < 0) return 0;
    
    int ans = INT32_MAX;
    int end = sqrt(n);
    int i = 1;
    while (i <= end)
    {
        int perfectSquare = i*i;
        int numOfPerfectSquares = 1 + numSquareHelper(n - perfectSquare);
        if (numOfPerfectSquares < ans)
        {
            ans = numOfPerfectSquares;
        }
        i++ ;
    }
    return ans;
}

int numSquares(int n)
{
    return numSquareHelper(n) - 1;
}

int mincostTickest_helper(vector<int>& days, vector<int>& costs, int i)
{
    // Base
    if (i >= days.size()) return 0;

    // 1 Day Pass Taken
    int cost1 = costs[0] + mincostTickest_helper(days, costs, i+1);

    // 7 Days Pass Taken
    int passEndDay = days[i] + 7 - 1;
    int j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++ ;
    }
    int cost7 = costs[1] + mincostTickest_helper(days, costs, j);

    // 30 Days Pass Taken
    passEndDay = days[i] + 30 - 1;
    j = i;
    while (j < days.size() && days[j] <= passEndDay)
    {
        j++ ;
    }
    int cost30 = costs[2] + mincostTickest_helper(days, costs, j);

    return min(cost1, min(cost7, cost30));
}

int mincostTickets(vector<int>& days, vector<int>& costs)
{
    return mincostTickest_helper(days, costs, 0);
}   

int main()
{
    string s1 = "acfyjc"; char Ch = 'd';
    int ans1 = -1; int ans2 = -1;
    // cout << LastOccLTR(s, Ch, 0, ans1) << endl;
    // cout << LastOccRTL(s, Ch, s.size()-1, ans2) << endl;

    // cout << s1 << endl;
    // ReverseString(s, 0, s.size() - 1);
    // cout << s1 << endl;

    string s21 = "456";
    string s22 = "77";
    // cout << addString(s21, s22) << endl;

    string s3 = "racetar";
    // cout << PalindromeRE(s3) << endl;

    vector<int> v1 = {1, 2, 3, 4, 5};
    // printSubarray(v1);

    string s4 = "daabcbaabcbc";
    string part = "abc";
    // cout << RemoveOccurences(s4, part) << endl;

    vector<int> Prices = {7, 1, 5, 3, 6, 4};
    // cout << maxProfit(Prices) << endl;

    // cout << numberToWords(INT32_MAX) << endl;

    string s = "abcdefg";
    string p = "ab*f?";
    // cout << isMatch(s, p) << endl;

    // cout << numRollsToTarget(2, 6, 7) << endl;

    // cout << numSquares(12) << endl;

    vector<int> Days = {2, 5};
    vector<int> Costs = {1, 4, 25};
    cout << mincostTickets(Days, Costs) << endl;

    return 0;
}