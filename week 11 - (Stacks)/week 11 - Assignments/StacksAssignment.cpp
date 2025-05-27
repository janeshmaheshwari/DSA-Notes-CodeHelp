#include <iostream>
using namespace std;

// N Stacks in an Array
class NStack
{
    int *a, *top, *next; // Intializing All Arrays
    int n; // Number of Stacks
    int size; // Size of main Array (*a, *next)
    int freeSpot; // Indicates next Free Space in main Array

public:
    // Initializing Constructor with Required Parameters
    NStack(int _n, int _size) : n(_n), size(_size)
    {
        freeSpot = 0; // Intializing Free Space to 0
        top = new int(n);
        a = new int(size);
        next = new int(size);

        // Initializing Top Elements of each Stack as -1 in the Top Array
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // Initializing Every Element in Next Array as it's next Index
        for (int i = 0; i < size; i++)
        {
            next[i] = i + 1;
        }
        next[size - 1] = -1; // Last Element of Next Array = -1 (Array Finished)

        cout << "Constructor Called Successfully !!!" << endl;
    }

    // X = Element, m = Stack Number (from 1 to n)
    bool push(int X, int m) // Push X in m'th Stack
    {
        if(freeSpot == -1)
        {
            cout << "Stack OverFlow !" << endl;
            return false;
        }

        // 1. Find Index
        int index = freeSpot;

        // 2. Update Free Spot
        freeSpot = next[index];

        // 3. Insert
        a[index] = X;

        // 4. Update Next
        next[index] = top[m-1];

        // 5. Update Top
        top[m - 1] = index;

        cout << "Element Pushed Successfully !" << endl;
        return true;
    }

    // m = Stack Number (from 1 to n)
    int pop(int m) // Pop from m'th Stack
    {
        if(top[m-1] == -1)
        {
            cout << "Stack UnderFlow !" << endl;
            return -1;
        }

        // 1. Find Index with help of Top Array
        int index = top[m-1];

        // 2. Update Top with help of Next Array
        top[m-1] = next[index];

        // 3. Storing Popped Element
        int poppedElement = a[index];

        // 4. Freeing Up Next Array Element
        next[index] = freeSpot;

        // 5. Update Free Spot
        freeSpot = index;

        cout << "Element Popped Successfully !" << endl;
        return poppedElement;
    }

    ~NStack()
    {
        delete[] a;
        delete[] top;
        delete[] next;
        cout << "Destructor Called Successfully !!!" << endl;
    }
};

int main()
{
    NStack st(3, 6);
    
    while(true)
    {
        int X, m;
        string operation;

        cout << "Enter 'push' , 'pop' or 'exit'\n=> ";
        cin >> operation;

        if (operation == "push")
        {
            cout << "Enter Element and Stack \n=> ";
            cin >> X >> m;
            st.push(X, m);
        }
        else if(operation == "pop")
        {
            cout << "Enter Stack \n=> ";
            cin >> m;
            cout << st.pop(m) << endl;
        }
        else if(operation == "exit")
        {
            break;
        }
        else
        {
            cout << "Wrong Input" << endl;
        }
    }

    return 0;
}