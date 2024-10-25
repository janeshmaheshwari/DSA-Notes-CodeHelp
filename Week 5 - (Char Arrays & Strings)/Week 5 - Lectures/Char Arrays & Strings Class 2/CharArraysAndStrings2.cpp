#include <iostream>
#include<vector>
#include<string>
using namespace std;

string RemoveAdjacentDupilcates(string s)
{
    string ans = "";
    int index = 0;

    while (index < s.length())
    {
        if (ans[ans.length()-1] == s[index] && ans.length() > 0)
        {
            ans.pop_back();
        }
        else
        {
            ans.push_back(s[index]);
        }
        index++ ;
    }
    return ans;
}

string RemoveKAdjacentDupilcates(string s, int k) //HW
{
    string ans = "";
    int index = 0;

    while (index < s.length())
    {
        if (ans[ans.length()-k + 1] == s[index] && ans.length() >= k-1)
        {
            for (int i = ans.length()-k + 1; i < ans.length(); i++)
            {
                if (ans[i] == s[index])
                {
                    if (i == ans.length() - 1)
                    {
                        for (int i = ans.length() - 1; i > ans.length()-k; i--)
                        {
                            ans.pop_back();
                        } 
                    }
                    
                }
                else
                {
                    ans.push_back(s[index]);
                }
            }    
        }
        else
        {
            ans.push_back(s[index]);   
        }
        index++ ;
    }
    return ans;
}

string RemoveOccuerences(string s, string part)
{
    while (s.find(part) != string::npos)
    {
        s.erase(s.find(part), part.length());
    }
    return s;
}

bool CheckPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        else
        {
            i++ ;
            j-- ;
        }
    }
    return true;
}

bool CheckPalindromRemoval(string s) //Atmost 1 Removal
{
    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        if (s[i] == s[j])
        {
            i++ ;
            j-- ;
        }
        else
        {
            bool ans1 = CheckPalindrome(s, i+1, j);
            bool ans2 = CheckPalindrome(s, i, j-1);
            return (ans1||ans2);
        }
    }
    return true;
}

int findMinDifference(vector<string>& timepoints) //HW
{
    vector<int> time;

    for (int i = 0; i < timepoints.size(); i++)
    {

    }

    return 0;
}

int expand(string s, int i, int j)
{
    int count = 0;

    while (s[i] == s[j] && i>=0 && j < s.length())
    {
        count++ ;
        i-- ;
        j++ ;
    }
    return count;
}

int countSubStrings(string s)
{
    int totalCount = 0;
    
    for (int centre = 0; centre < s.length(); centre++)
    {
        int OddCount = expand(s, centre, centre);
        int evenCount = expand(s, centre, centre+1);
        totalCount = totalCount + OddCount + evenCount;
    }
    return totalCount;
}

int main()
{
    string s1 = "abbaca";
    // cout << RemoveAdjacentDupilcates(s1) << endl;

    string s2 = "deeedbbcccbdaa";
    int k = 3;
    // cout << RemoveKAdjacentDupilcates(s2, k) << endl;

    string s3 = "abaccbabaddcbaccd";
    string part = "cba";
    // cout << RemoveOccuerences(s3, part) << endl;

    string s4 = "madmam";
    // cout << CheckPalindromRemoval(s4) << endl;

    vector<string> s5 = {"23:59", "12:15", "00:00"};
    // cout << findMinDifference(s5) << endl;

    string s6 = "abcba";
    cout << countSubStrings(s6) << endl;
    
    return 0;
}