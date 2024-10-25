#include<bits/stdc++.h>
#include <iostream>
#include<vector>
#include<string>
using namespace std;

string DecodeMessage(string key, string message)
{
    //Mapping every element of key to the character
    //Starting with 'a'
    char start = 'a';
    char mapping[256] = {0};

    //(ch) is every element of string key
    for (auto ch : key)
    {
        if (ch != ' ' && mapping[ch] == 0)
        {
            //Checking whether the element(ch) isn't space
            //Int of that element(ch) in string mapping is null
            mapping[ch] = start;
            start++ ;
        }
    }
    
    //Creating a new string ans
    //Using the string mapping to decode in ans
    string ans;

    for (auto ch : message)
    {
        if (ch == ' ')
        {
            ans.push_back(' ');
        }
        else
        {
            // char decodedChar = mapping[ch];
            // ans.push_back(decodedChar);

            ans.push_back(mapping[ch]);
        }
    }
    return ans;
}

int garbageCollection(vector<string>& garbage, vector<int>& travel)
{
    //Creating the time variables for picking
    int pickP = 0;
    int pickM = 0;
    int pickG = 0;

    //Creating the time variables for travelling
    int travelP = 0;
    int travelM = 0;
    int travelG = 0;

    //Creating the last variables for their last occurence to save travelling time
    int LastP = 0;
    int LastM = 0;
    int LastG = 0;

    for (int i = 0; i < garbage.size(); i++)
    {
        string curr = garbage[i];
        for (auto ch : curr)
        {
            if (ch == 'P')
            {
                pickP++ ;
                LastP = i;
            }
            else if (ch == 'M')
            {
                pickM++ ;
                LastM = i;
            }
            else if (ch == 'G')
            {
                pickG++ ;
                LastG = i;
            }
        }
    }

    for (int i = 0; i < LastP; i++)
    {
        travelP += travel[i];
    }
    for (int i = 0; i < LastM; i++)
    {
        travelM += travel[i];
    }
    for (int i = 0; i < LastG; i++)
    {
        travelG += travel[i];
    }

    return (pickP + travelP + pickG + travelG + pickM + travelM);
}

static string str;
static bool compare(char ch1, char ch2)
{
    return(str.find(ch1) < str.find(ch2));
}

string customSorting(string order, string s)
{
    str = order;
    sort(s.begin(), s.end(), compare);
    return s;
}

void createMapping(string& str)
{
    char start = 'a';
    char mapping[256] = {0};

    for (auto ch : str)
    {
        if (mapping[ch] == 0)
        {
            mapping[ch] = start;
            start++ ;
        }
    }

    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        str[i] = mapping[ch];
    }
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern)
{
    vector<string> ans;
    createMapping(pattern);

    for (string s : words)
    {
        string tempString = s;
        createMapping(tempString);

        if (tempString == pattern)
        {
            ans.push_back(s);
        }
    }
    return ans;
}

void PrintVector(vector<string> s)
{
    for (auto ch : s)
    {
        cout << ch << " ";
    }
    cout << endl;
}

int main()
{
    string key = "the quick brown fox jumps over the lazy dog";
    string message = "vkbs bs t suepuv";
    // cout << DecodeMessage(key, message) << endl;

    vector<string> garbage = {"G", "P", "PG", "GG"};
    vector<int> travel = {2, 4, 3};
    // cout << garbageCollection(garbage, travel) << endl;

    string order = "cbafg";
    string s = "abcd";
    // cout << customSorting(order, s) << endl;

    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    // PrintVector(findAndReplacePattern(words, pattern));   

    return 0;
}