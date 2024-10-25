#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

bool ValidAnagram1(string s, string t)
{
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());
    if (s == t) return true;
    return false;
}

bool ValidAnagram2(string s, string t)
{
    int freqTable[26] = {0};
    for (auto i : s)
    {
        freqTable[i - 97]++;
    }
    for (auto i : t)
    {
        freqTable[i - 97]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (freqTable[i] != 0)
        {
            return false;
        }
    }
    return true;
}

string ReverseOnlyLetters1(string str)
{
    int s = 0;
    int e = str.size() - 1;
    while (s < e)
    {
       while (s < e && !((str[s] >= 'A' && str[s] <= 'Z') || (str[s] >= 'a' && str[s] <= 'z')))
        {
            s++;
        }
        while (s < e && !((str[e] >= 'A' && str[e] <= 'Z') || (str[e] >= 'a' && str[e] <= 'z')))
        {
            e--;
        }
        if (s < e)
        {
            swap(str[s], str[e]);
            s++;
            e--;
        }
    }
    return str;
}

string ReverseOnlyLetters2(string str)
{
    int s = 0;
    int e = str.size() - 1;
    while (s < e)
    {
        if (isalpha(str[s]) && isalpha(str[e]))
        {
            swap(str[s], str[e]);
            s++, e--;
        }
        else if (!isalpha(str[s]))
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    return str;
}

string LongestCommonPrefix(vector<string> s)
{
    string ans;
    int index = 0;

    while (true)
    {
        char curr_char = s[0][index];  // Start with the first string's character at index

        for (int i = 1; i < s.size(); i++)
        {
            // Check if index is out of bounds or if characters don't match
            if (index >= s[i].size() || s[i][index] != curr_char)
            {
                return ans;  // If mismatch or out of bounds, return the accumulated prefix
            }
        }

        // If all strings have the same character at index, add it to the prefix
        ans.push_back(curr_char);
        index++;
    }

    return ans;  // This line is actually never reached
}

bool isVowel(char ch)
{
    ch = tolower(ch);
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

string reverseVowels(string str)
{
    int s = 0;
    int e = str.size() - 1;
    while (s < e)
    {
        if (isVowel(str[s]) && isVowel(str[e]))
        {
            swap(str[s], str[e]);
            s++, e--;
        }
        else if (isVowel(str[s]) == 0)
        {
            s++;
        }
        else
        {
            e--;
        }
    }
    return str;
}

bool isIsomorphic(string s, string t)
{
    int hash[256] = {0}; //Mapping of each char of Language 's' to language 't'
    bool istCharMapped[256] = {0}; //stores if t[i] char already mapped with s[i]

    for (int i = 0; i < s.size(); i++)
    {
        if (hash[s[i]] == 0 && istCharMapped[t[i]] == 0)
        {
            hash[s[i]] = t[i];
            istCharMapped[t[i]] = true;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (char(hash[s[i]]) != t[i])
        {
            return false;
        } 
    }
    return true;
}

vector<vector<string>> GroupAnagrams(vector<string> strs)
{
    map <string, vector<string>> mp;

    for (string str : strs)
    {
        string s = str;
        sort(s.begin(), s.end());
        mp[s].push_back(str);
    }
    vector<vector<string>> ans;
    for (auto it = mp.begin(); it != mp.end(); it++ )
    {
        ans.push_back(it->second);
    }
    return ans;
}

bool isPalindrome(string& s, int start, int end)
{
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++, end--;
    }
    return true;
}

string longestPalindrome(string s)
{
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j-i+1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

int myAtoi(string s)
{
    int ans = 0, i = 0, sign = 1;

    // Skip whitespace
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }

    // Check for sign
    if (i < s.size() && (s[i] == '-' || s[i] == '+'))
    {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }

    // Process digits
    while (i < s.size() && isdigit(s[i]))
    {
        if (ans > INT32_MAX / 10 || (ans == INT32_MAX / 10 && s[i] - '0' > 7))
        {
            return sign == -1 ? INT32_MIN : INT32_MAX;
        }
        ans = ans * 10 + (s[i] - '0');
        i++;
    }

    return ans * sign;
}

int stringCompression(vector<char>& chars)
{
    int index = 0, count = 1;
    char prev = chars[0];
    
    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] == prev)
        {
            count++;
        }
        else
        {
            chars[index++] = prev;
            if (count > 1)
            {
                int start = index;
                while (count)
                {
                    chars[index++] = (count % 10) + '0';
                    count /= 10;
                }
                reverse(chars.begin() + start, chars.begin() + index);
            }
            prev = chars[i];
            count = 1;
        }
    }
    
    chars[index++] = prev;
    if (count > 1)
    {
        int start = index;
        while (count)
        {
            chars[index++] = (count % 10) + '0';
            count /= 10;
        }
        reverse(chars.begin() + start, chars.begin() + index);
    }
    
    return index;
}

string intToRoman(int n)
{
    string romanSymbols[] = {"M", "CM", "D", "CD", "C", "XC", "L" ,"XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string ans;
    for (int i = 0; i < 13; i++)
    {
        while (n >= values[i])
        {
            ans+=romanSymbols[i];
            n-=values[i];
        }
    }
    return ans;
}

string ZigZag(string s, int numrows)
{
    if (numrows == 1) return s;
    
    vector<string>zigzag(numrows);
    
    int i =0, row = 0;
    bool direction = 1; //1 -> top to bottom, 0 -> bottom to top

    while (true)
    {
        if (direction)
        {
            while (row < numrows &&  i < s.size())
            {
                zigzag[row++].push_back(s[i++]);
            }
            row = numrows - 2;
        }
        else
        {
            while (row >= 0 &&  i < s.size())
            {
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if(i >= s.size()) break;
        direction = !direction;
    }

    string ans;
    for (int i = 0; i < zigzag.size(); i++)
    {
        ans += zigzag[i];
    }
    return ans;
}

static bool mycomp(string a, string b)
{   
    string t1 = a + b;
    string t2 = b + a;
    return t1 > t2;
}

string largestNumber(vector<int>& nums)
{
    vector<string> snums;
    for (int n : nums)
    {
        snums.push_back(to_string(n)); 
    }
    
    sort(snums.begin(), snums.end(), mycomp);
    if (snums[0] == "0") return "0";
    string ans = "";

    for (string str : snums)
    {
        ans+=str;
    }
    return ans;
}

string recognizeString(string s)
{
    int hash[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i] - 'a']++;
    }

    char max_freq_char = 'a';
    int max_freq = hash[0];
    for (int i = 1; i < 26; i++)
    {
        if (hash[i] > max_freq)
        {
            max_freq = hash[i];
            max_freq_char = i + 'a';
        }
    }
    
    int index = 0;
    while ((max_freq) && (index < s.size()))
    {
        s[index] = max_freq_char;
        max_freq--;
        index+=2;
    }
    if (max_freq != 0)
    {
        return "";
    }
    hash[max_freq_char - 'a'] = 0;

    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            index = index >= s.size() ? 1 : index;
            s[index] = i + 'a';
            hash[i]--;
            index += 2;
        }
    }
    return s;
}

int firstOccurence(string haystack, string needle)
{
    int n = haystack.size();
    int m = needle.size();

    for (int i = 0; i <= n - m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (needle[j] != haystack[i + j])
            {
                break;
            }
            if (j == m - 1)
            {
                return i;
            }
        }
    }
    return -1;
}

bool CheckLastKchar(string ans, char Ch, int k_1)
{
    int it = ans.size() - 1;
    for (int i = 0; i < k_1; i++)
    {
        if (Ch != ans[it - i])
        {
            return false;
        }
    }
    return true;
}

string removeDuplicates1(string s, int k)
{
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        char& newCh = s[i];
        if (ans.size() < k-1)
        {
            ans.push_back(s[i]);
        }
        else
        {
            if (CheckLastKchar(ans, newCh, k-1))
            {
                for (int j = 0; j < k-1; j++)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans.push_back(newCh);
            }
        }
    }
    return ans;
}

string removeDuplicates2(string s, int k) //Two Pointer approach
{
    int i = 0, j = 0;
    vector<int> count(s.size());
    while (j < s.size())
    {
        s[i] = s[j];
        count[i] = 1;
        if (i > 0 && s[i] == s[i-1])
        {
            count[i] += count[i-1];
        }
        if (count[i] == k)
        {
            i-=k;
        }
        i++, j++;
    }
    return s.substr(0, i);
}

int convertToMin(string s)
{
    return (s[0]-'0')*600 + (s[1]-'0')*60 + (s[3]-'0')*10 + (s[4]-'0');
}

int findMinDifference(vector<string>& timePoints)
{
    vector<int> mins;
    for (string time : timePoints)
    {
        mins.push_back(convertToMin(time));
    }

    sort(mins.begin(), mins.end());
    int ans = 721;

    for (int i = 0; i < mins.size() - 1; i++)
    {
        ans = min(ans, mins[i+1] - mins[i]);
    }

    //Last Diff
    int lastdiff = mins[0] + 1440 - mins[mins.size() - 1];
    ans = min(ans, lastdiff);
    
    return ans;
}

int countDevices(string& binary)
{
    int count = 0;
    for (char b : binary)
    {
        count += b - '0';
    }
    return count;
}

int numberOfBeams(vector<string>& bank)
{
    vector<int> devices;
    for (string row : bank)
    {
        devices.push_back(countDevices(row));
    }
    int beams = 0;
    for (int i = 0; i < devices.size(); i++)
    {
        int j = i + 1;
        while (j < devices.size())
        {
            beams += devices[i] * devices[j];
            if (devices[j] == 0)
            {
                j++;
            }
            else
            {
                break;
            }
        }
    }
    return beams;
}

int main()
{
    string s1 = "anagram";
    string t1 = "nagaram";
    // cout << ValidAnagram1(s1, t1) << endl;
    // cout << ValidAnagram2(s1, t1) << endl;

    // string s2 = "Test1ng-Leet=code-Q!";
    string s2 = "Janesh-Maheshwari";
    // cout << ReverseOnlyLetters1(s2) << endl;
    // cout << ReverseOnlyLetters2(s2) << endl;

    vector<string> S1 = {"flower", "flow", "flower"};
    // cout << LongestCommonPrefix(S1) << endl;

    string s3 = "LeEtCodE";
    // cout << reverseVowels(s3) << endl;

    string s4 = "egg";
    string t4 = "add";
    // cout << isIsomorphic(s4, t4)<< endl;

    vector<string> S2 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    // for (auto i : GroupAnagrams(S2))
    // {
    //     cout << "-> ";
    //     for (auto j  : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    string s5 = "babad"; //Even "aba" can be answer
    // cout << longestPalindrome(s5) << endl; //But only "bab" is also correct

    string s6 = "    -45Janesh";
    // cout << myAtoi(s6) << endl;

    vector<char> C1 = {'a', 'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'd'};
    // cout << stringCompression(C1) << endl;
    // for (char ch : C1)
    // {
    //     cout << ch << " ";
    // }

    // cout << intToRoman(1994) << endl;

    // cout << ZigZag("ABCDEFG", 3) << endl;

    vector<int> nums = {3, 30, 34, 5, 9};
    // cout << largestNumber(nums) << endl;

    string s7 = "aaabb";
    // cout << recognizeString(s7) << endl;

    string s81 = "leetsadcode";
    string s82 = "sad";
    // cout << firstOccurence(s81, s82) << endl;

    string s9 = "deeedbbcccbdaa";
    int k9 = 3;
    // cout << removeDuplicates1(s9, k9) << endl;

    vector<string> timePoints = {"23:59", "11:59", "00:01"};
    // cout << findMinDifference(timePoints) << endl;

    vector<string> bank = {"011001", "000000", "010100", "001000"};
    // cout << numberOfBeams(bank) << endl;

    return 0;
}