#include <iostream>
#include <queue>
using namespace std;

void FirstNonRepeating(string &str)
{
    queue<char> q;
    int freq[26] = {0};
    
    for(int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        freq[ch-'a']++;
        q.push(ch);
        
        while(!q.empty())
        {
            char frontCh = q.front();
            if(freq[frontCh-'a'] > 1)
            {
                q.pop();
            }
            else
            {
                cout << frontCh << "->";
                break;
            }
        }
        
        if(q.empty())
        {
            cout << "#" << "->";
        }
    }
}

vector<int> maxSlidingWindow(vector<int>& nums, int k)
{
    vector<int> ans;
    deque<int> dq;

    // 1st Window ko Process Karo
    for(int i = 0; i < k; i++)
    {
        int element = nums[i];

        // Queue ke andar chotte Element ko remove karo
        while(element > nums[dq.back()] && !dq.empty())
        {
            dq.pop_back();
        }

        // ab Insert Kardo
        dq.push_back(i);
    }

    // Remaining Window ko Process Karo
    for(int i = k; i < nums.size(); i++)
    {
        // Ans Store
        ans.push_back(nums[dq.front()]);

        // Removal
        // 1. Out of Range
        if(i - dq.front() >= k && !dq.empty())
        {
            dq.pop_front();
        }
        // 2. Chotte Elements ko Pop Kardo
        int element = nums[i];
        while(element > nums[dq.back()] && !dq.empty())
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }

    // Last Window ko Process Karo
    ans.push_back(nums[dq.front()]);

    return ans;
}

int main()
{
    string str = "ababc";
    string str1 = "facfdcad";
    FirstNonRepeating(str1);

    return 0;
}