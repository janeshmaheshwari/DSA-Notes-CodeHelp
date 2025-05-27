#include <iostream>
#include <queue>
#include <deque>
using namespace std;

// Implement Queue from Scratch (Array / L-L)

class Queue{
// Queue :- Push - Rear, Pop - Front
public:
    int *arr;
    int size;
    int front;
    int rear;
    
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }
    
    void push(int val)
    {
        if(rear == size-1)
        {
            cout << "Queue OverFlow !!!" << endl;
            return;
        }
        else if(front == -1 && rear == -1) // Empty
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        else
        {
            arr[++rear] = val;
        }
    }
    
    void pop()
    {
        if(front == -1 && rear == -1)
        {
            cout << "Queue UnderFlow !!!" << endl;
            return;
        }
        else if(front == rear) // Single Element
        {
            arr[front] = -1; // Element Removed
            front = -1;
            rear = -1;
        }
        else
        {
            arr[front++] = -1;
        }
    }
    
    bool isEmpty()
    {
        return (front == -1 && rear == -1) ? true : false;
    }
    
    int getSize()
    {
        return (front == -1 && rear == -1) ? 0 : rear - front + 1;
    }
    
    int getFront()
    {
        return (front == -1) ? -1 : arr[front];
    }
    
    int getRear()
    {
        return (rear == -1) ? -1 : arr[rear];
    }
    
    void print()
    {
        cout << "Printing Queue :" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        } cout << endl;
    }
};

// Implement Circular Queue

class CQueue{
// Circular Queue - To Prevent Memory Loss
public:
    int *arr;
    int size;
    int front;
    int rear;
    
    CQueue(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // OverFlow
        if((front == 0 && rear == size-1) || (front - rear == 1))
        {
            cout << "Queue OverFlow !!!" << endl;
            return;
        }
        
        // Empty Case - First Element
        else if(front == -1 && rear == -1) // Empty
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        
        // Circular Nature
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        
        // Normal Case
        else
        {
            arr[++rear] = val;
        }
    }
    
    void pop()
    {
        // UnderFlow
        if(front == -1 && rear == -1) // Empty
        {
            cout << "Queue UnderFlow !!!" << endl;
            return;
        }
        
        // Single Element - Empty
        else if(front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        
        // Circular Nature
        else if(front == size-1)
        {
            arr[front] = -1;
            front = 0;
        }

        // Normal Case
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    
    void print()
    {
        cout << "Printing Queue :" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        } cout << endl;
    }
};

// Implement Doubly Ended Queue (deque)

class Deque{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size)
    {
        arr = new int[size];
        this->size = size;
        front = -1;
        rear = -1;
    }

    void pushBack(int val)
    {
        // OverFlow
        if((front == 0 && rear == size-1) || (front - rear == 1))
        {
            cout << "Queue OverFlow !!!" << endl;
            return;
        }
        
        // Empty Case - First Element
        else if(front == -1 && rear == -1) // Empty
        {
            front++;
            rear++;
            arr[rear] = val;
        }
        
        // Circular Nature
        else if(rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
        }
        
        // Normal Case
        else
        {
            arr[++rear] = val;
        }
    }

    void pushFront(int val)
    {
       // OverFlow
       if((front == 0 && rear == size-1) || (front - rear == 1))
       {
           cout << "Queue OverFlow !!!" << endl;
           return;
       }
       
       // Empty Case - First Element
       else if(front == -1 && rear == -1) // Empty
       {
           front++;
           rear++;
           arr[front] = val;
       }
       
       // Circular Nature
       else if(front == 0 && rear != size-1)
       {
           front = size-1;
           arr[front] = val;
       }
       
       // Normal Case
       else
       {
           arr[--front] = val;
       }
    }

    void popFront()
    {
        // UnderFlow
        if(front == -1 && rear == -1) // Empty
        {
            cout << "Queue UnderFlow !!!" << endl;
            return;
        }
        
        // Single Element - Empty
        else if(front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        
        // Circular Nature
        else if(front == size-1)
        {
            arr[front] = -1;
            front = 0;
        }

        // Normal Case
        else
        {
            arr[front] = -1;
            front++;
        }
    }
    void popBack()
    {
        // UnderFlow
        if(front == -1 && rear == -1) // Empty
        {
            cout << "Queue UnderFlow !!!" << endl;
            return;
        }
        
        // Single Element - Empty
        else if(front == rear)
        {
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        
        // Circular Nature
        else if(rear == 0)
        {
            arr[rear] = -1;
            rear = size-1;
        }

        // Normal Case
        else
        {
            arr[rear--] = -1;
        }
    }
};

int main()
{
/*
    // Creation
    queue<int> q;
    
    // Insertion
    q.push(5);
    
    // Size
    cout << "Size of Queue : " << q.size() << endl;
    
    // Empty
    q.empty() ? cout << "Empty" : cout << "Not Empty" << endl;
    
    // Remove
    q.pop();
    cout << "Size of Queue : " << q.size() << endl;
    q.empty() ? cout << "Empty" << endl : cout << "Not Empty";

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front Element : " << q.front() << endl;
    cout << "Back Element : " << q.back() << endl;
*/
/*
    Queue q(5);
    q.print();

    q.push(10);
    q.print();
    
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();

    cout << "Size of Queue : " << q.getSize() << endl;
    
    q.pop();
    q.print();
    cout << "Size of Queue : " << q.getSize() << endl;
    cout << "Is Queue Empty : " << q.isEmpty() << endl;
    
    q.push(100);
    q.print();
    
    q.pop();
    q.pop();
    q.pop();
    q.print();
    cout << q.getFront() << endl;
    cout << "Size of Queue : " << q.getSize() << endl;
    
    q.pop();
    cout << "Is Queue Empty : " << q.isEmpty() << endl;
    cout << "Size of Queue : " << q.getSize() << endl;
*/
/*
    CQueue q(5);
    q.print();
    
    q.push(10);
    q.print();
    
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.print();
    
    q.push(60);
    q.print();
    
    q.pop();
    q.pop();
    q.pop();
    q.print();
    
    q.push(100);
    q.print();
    
    q.push(200);
    q.push(300);
    q.print();
    
    q.push(400);
    q.print();

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.print();
    
    q.pop();
    q.print();
*/
/*
    deque<int> dq;
    dq.push_front(10);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    
    dq.push_back(100);
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    
    dq.pop_front();
    cout << dq.front() << endl;
    cout << dq.back() << endl;
    
    dq.pop_back();
    cout << dq.front() << endl;
    cout << dq.back() << endl;
*/

    return 0;
}