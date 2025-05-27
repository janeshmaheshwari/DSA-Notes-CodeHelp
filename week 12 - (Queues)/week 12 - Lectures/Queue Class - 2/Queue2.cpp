#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

void printQueue(queue<int> q)
{
    while(!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    } cout << endl;
}

void reverseQueue1(queue<int>& q)
{ // By Stack :-
    stack<int> st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

void reverseQueue2(queue<int>& q)
{ // By Recurssion :-
    // Base Case
    if(q.empty()) return;
    
    // One Case
    int temp = q.front();
    q.pop();
    
    // Recursion
    reverseQueue2(q);
    
    // DnC
    q.push(temp);
}

void reverseFirstK(queue<int>& q, int k)
{ // By Stack :-
    stack<int> st;
    int n = q.size();
    if (k > n || k < 2) return;

    // Starts from k == 2 && n == 3
    for (int i = 0; i < k; i++)
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    for (int i = 0; i < n-k; i++)
    {
        q.push(q.front());
        q.pop();
    }
}

void interLeaveQueue(queue<int>& q)
{ // For q.size() == Even
    queue<int> q2;
    int size = q.size();

    for (int i = 0; i < size/2; i++)
    {
        q2.push(q.front());
        q.pop();
    }

    for (int i = 0; i < size/2; i++)
    {
        q.push(q2.front());
        q2.pop();

        q.push(q.front());
        q.pop();
    }
}

void interLeaveOddQueue(queue<int>& q)
{ // For q.size() == Odd
    // Work in Progress !!!
}

void printFirstNegative(int *arr, int n, int k)
{
    deque<int> dq;

    for (int index = 0; index < k; index++) // 1st Window
    {
        if (arr[index] < 0) // All (-ve) of 1st Window
        {
            dq.push_back(index); // Store in deQue
        }
    }
    
    for (int index = k; index < n; index++) // 2nd Window to Last
    {
        if (dq.empty())
        {
            cout << "0 " << endl;
        }
        else
        {
            cout << arr[dq.front()] << " ";
        }

        if (!dq.empty() && dq.front() <= index - k) 
        {
            dq.pop_front();
        }
        
        if (arr[index] < 0)
        {
            dq.push_back(index);
        } 
    }
    
    if (dq.empty())
    {
        cout << "0 " << endl;
    }
    else
    {
        cout << arr[dq.front()] << " ";
    }
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    
    // printQueue(q);
    // reverseQueue1(q);
    // printQueue(q);

    // printQueue(q);
    // reverseQueue2(q);
    // printQueue(q);
    
    // printQueue(q);
    // reverseFirstK(q, 4);
    // printQueue(q);
    
    // printQueue(q);
    // interLeaveQueue(q);
    // printQueue(q);
    
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int size = 7;
    int k = 3;
    printFirstNegative(arr, size, k);

    return 0;
}