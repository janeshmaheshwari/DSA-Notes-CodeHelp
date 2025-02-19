#include <stack>
#include <iostream>
using namespace std;

class Stack
{
public:
    int* arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int data)
    {
        if (top == size-1)
        {
            cout << "Stack overflow !!!" << endl;
            return;
        }
        else
        {
            top++;
            arr[top] = data;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "Stack underflow !!!" << endl;
            return;
        }
        else
        {
            top--;
        }
    }
    bool isEmpty()
    {
        return top == -1 ? 1 : 0;
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty !!!" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }
    int getSize()
    {
        return top+1;
    }

    void print()
    {
        cout << "Stack : ";
        for (int i = 0; i < getSize(); i++)
        {
            cout <<arr[i] << " ";
        }
        cout << endl;
    }
};

void solve(stack<int>& st, int pos, int &ans)
{
    //Base Case
    if (pos == 1)
    {
        ans = st.top();
        return;
    }

    // 1 Case Solve
    pos--;
    int temp = st.top();
    st.pop();

    // Recursion
    solve(st, pos, ans);

    // Backtrack
    st.push(temp);
}

int getMiddleElement(stack<int>& st)
{
    int size = st.size();
    if (st.empty())
    {
        cout << "Stack is Empty !!!" << endl;
        return -1;
    }
    else
    {
        int pos = 0;
        if (size & 1) //Odd
        {
            pos = size/2 + 1;
        }
        else //Even
        {
            pos = size/2;
        }
        int ans;
        solve(st, pos, ans);
        return ans;
    }
}

void insertAtBottom(stack<int>& st, int &data)
{
    if (st.empty())
    {
        st.push(data);
        return;
    }
    
    int temp = st.top();
    st.pop();

    insertAtBottom(st, data);

    st.push(temp);
}

void reverseStack(stack<int>& st)
{
    if (st.empty()) return; //Base Case
    
    int temp = st.top(); //1 Case
    st.pop();

    reverseStack(st); //Recursion

    insertAtBottom(st, temp); //Backtrack
}

void InsertSorted(stack<int>& st, int &data)
{
    if (st.empty() || data > st.top())
    {
        st.push(data);
        return;
    }
    
    int temp = st.top();
    st.pop();

    InsertSorted(st, data);

    st.push(temp);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack(st);

    InsertSorted(st, temp);
}

int main()
{
    // stack<int> st;
    // st.push(10);
    // st.push(20);
    // st.push(30);

    // cout << "Size of Stack is " << st.size() << endl;

    // st.pop();

    // if (st.empty())
    // {
    //     cout << "Stack is Empty !!!" << endl;
    // }
    // else
    // {
    //     cout << "Stack is not Empty" << endl;
    // }
    
    // cout << st.top() << endl;



    Stack st1(8); // Use Your Stack from Here !!!



    // string str = "Janesh";
    // stack<char> st2;

    // for (int  i = 0; i < str.length(); i++)
    // {
    //     char ch = str[i];
    //     st2.push(ch);
    // }cout << endl;

    // while (!st2.empty())
    // {
    //     cout << st2.top();
    //     st2.pop();
    // }cout << endl;



    // stack<int> st3;
    // st3.push(10);
    // st3.push(20);
    // st3.push(30);
    // st3.push(40);
    // st3.push(50);

    // int mid = getMiddleElement(st3);
    // cout << "Middle Element : " << mid << endl;



    // stack<int> st4;
    // st4.push(10);
    // st4.push(20);
    // st4.push(30);

    // int data = 400;
    // insertAtBottom(st4, data);

    // while (!st4.empty())
    // {
    //     cout << st4.top() << " ";
    //     st4.pop();
    // }cout << endl;



    // stack<int> st5;
    // st5.push(10);
    // st5.push(20);
    // st5.push(30);
    // st5.push(40);
    // st5.push(50);

    // reverseStack(st5);

    // while (!st5.empty())
    // {
    //     cout << st5.top() << " ";
    //     st5.pop();
    // }cout << endl;



    // stack<int> st6;
    // st6.push(10);
    // st6.push(20);
    // st6.push(30);
    // st6.push(40);
    // st6.push(50);

    // int data = 25;
    // InsertSorted(st6, data);

    // while (!st6.empty())
    // {
    //     cout << st6.top() << " ";
    //     st6.pop();
    // }cout << endl;



    stack<int> st7;
    st7.push(10);
    st7.push(2);
    st7.push(5);
    st7.push(0);
    st7.push(7);

    sortStack(st7);

    while (!st7.empty())
    {
        cout << st7.top() << " ";
        st7.pop();
    }cout << endl;

    return 0;
}