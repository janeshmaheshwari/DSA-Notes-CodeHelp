#include <iostream>
#include <vector>
#include <deque>
using namespace std;

class KQueue{
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;

public:
    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0) {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        for (int i = 0; i < k; i++) {
            front[i] = rear[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            next[i] = i+1;
        } next[n-1] = -1;

        cout << "Constructor Called Successfully !!!" << endl;
    }
    
    bool push(int x, int q) {
        if(freeSpot == -1) {
            cout << "Queue OverFlow !" << endl;
            return false;
        }

        int index = freeSpot;
        freeSpot = next[index]; // Updating FreeSpot

        if (front[q] == -1) {
            front[q] = index; // First Element
        }
        else{
            next[rear[q]] = index; // Updating next with help of rear
        }

        next[index] = -1; // Updating next, for next Value to be Pushed
        
        rear[q] = index; // Updating Rear
        arr[index] = x; // Pushing value in Array

        cout << "Element Pushed Successfully !" << endl;
        return true;
    }

    int pop(int q) {
        if(front[q] == -1){
            cout << "Queue UnderFlow !" << endl;
            return -1;
        }

        int index = front[q]; // Finding Index
        front[q] = next[index]; // Updating Front
        next[index] = freeSpot;
        freeSpot = index;

        cout << "Element Popped Successfully !" << endl;
        return arr[index]; 
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
        cout << "Destructor Called Successfully !!!" << endl;
    }
};

// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

int sumOfMinMaxOfAllWindowOfSizeK(std::vector<int>& nums, int k) {
    std::deque<int> dqMax, dqMin;
    int ans = 0;

    // Process the first window
    for (int i = 0; i < k; i++) {
        int element = nums[i];

        // Remove smaller elements from the back (for max deque)
        while (!dqMax.empty() && element > nums[dqMax.back()]) {
            dqMax.pop_back();
        }
        
        // Remove greater elements from the back (for min deque)
        while (!dqMin.empty() && element < nums[dqMin.back()]) {
            dqMin.pop_back();
        }

        // Insert the current element index in both deques
        dqMax.push_back(i);
        dqMin.push_back(i);
    }

    // Store the sum of min and max for the first window
    ans += nums[dqMax.front()] + nums[dqMin.front()];

    // Process the remaining windows
    for (int i = k; i < nums.size(); i++) {
        // Remove elements that are out of the current window
        if (!dqMax.empty() && dqMax.front() <= i - k) {
            dqMax.pop_front();
        }
        if (!dqMin.empty() && dqMin.front() <= i - k) {
            dqMin.pop_front();
        }

        int element = nums[i];

        // Remove smaller elements from the back (for max deque)
        while (!dqMax.empty() && element > nums[dqMax.back()]) {
            dqMax.pop_back();
        }
        
        // Remove greater elements from the back (for min deque)
        while (!dqMin.empty() && element < nums[dqMin.back()]) {
            dqMin.pop_back();
        }

        // Insert the current element index in both deques
        dqMax.push_back(i);
        dqMin.push_back(i);

        // Add the min and max of the current window to the answer
        ans += nums[dqMax.front()] + nums[dqMin.front()];
    }

    return ans;
}

int main()
{
    // KQueue q(3, 6);
    
    // while(true)
    // {
    //     int X, m;
    //     string operation;

    //     cout << "Enter 'push' , 'pop' or 'exit'\n=> ";
    //     cin >> operation;

    //     if (operation == "push")
    //     {
    //         cout << "Enter Element and Queue \n=> ";
    //         cin >> X >> m;
    //         q.push(X, m);
    //     }
    //     else if(operation == "pop")
    //     {
    //         cout << "Enter Queue \n=> ";
    //         cin >> m;
    //         cout << q.pop(m) << endl;
    //     }
    //     else if(operation == "exit")
    //     {
    //         break;
    //     }
    //     else
    //     {
    //         cout << "Wrong Input" << endl;
    //     }
    // }

    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    cout << sumOfMinMaxOfAllWindowOfSizeK(v, 3) << endl;

    return 0;
}