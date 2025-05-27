#include <iostream>
#include <stack>
#include <queue>
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
{ // By Stack
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
{ // By Recurssion
    
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

void reverseKElement(queue<int>& q, int k)
{ // By Stack
    stack<int> st;
    int n = q.size() - k;
    while (k)
    {
        st.push(q.front());
        q.pop();
        k--;
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    while (n)
    {
        q.push(q.front());
        q.pop();
        n--;
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
    
    printQueue(q);
    reverseKElement(q, 3);
    printQueue(q);

    return 0;
}