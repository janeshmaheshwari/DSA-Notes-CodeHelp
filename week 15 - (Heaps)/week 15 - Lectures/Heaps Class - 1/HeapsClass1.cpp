#include <iostream>
using namespace std;

// Visualize Heap by Tree
// Implement Head by Array
// Converting Tree to Array by Level Order Traversal

// For 1-Based Indexing (Array Representation) :-

// 1) Parent to Child
// -> Left Child = 2*i
// -> Right Child = 2*i + 1

// 2) Child to Parent
// -> Parent = i/2

// For 0-Based Indexing (Array Representation) :-

// 1) Parent to Child
// -> Left Child = 2*i + 1
// -> Right Child = 2*i + 2

// 2) Child to Parent
// -> Parent = (i-1)/2

// Ignoring 0th Element && Going in Deceding Order
class Heap
{
public:
    int *arr;
    int capacity;
    int size;

    Heap(int capacity) // Maximum Capacity
    {
        this->arr = new int[capacity];
        this->capacity = capacity;
        this->size = 0; // Current No. of Elements in Heap
    }

    // Simply insertion takes O(1) Time Complexity
    // But Heapifing it leads to TC = O(log(n)) OR TC = O(Height)
    void insert(int val)
    {
        if (size == capacity)
        {
            cout << "Heap OverFlow !!!" << endl;
            return;
        }

        size++;
        int index = size;
        arr[index] = val; // Putting Element

        // Comparing Element OR Heapify
        while (index > 1)
        {
            int parentindex = index/2;
            if (arr[index] > arr[parentindex])
            {
                swap(arr[index], arr[parentindex]);
                index = parentindex;
            }
            else break;
        }
    }

    void printHeap()
    {
        cout << "Printing Heap" << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << "->";
        }
        cout << endl;
    }

    int del() // Delete from Heap
    {
        int answer = arr[1];
        arr[1] = arr[size]; // Putting last Element on 1st Index
        size--;

        // Comparing Element OR Heapification
        int index = 1; // New Element
        while (index < size)
        {
            int leftIndex = 2 * index;
            int rightIndex = 2 * index + 1;

            // Assume Index to be greatest
            int largestKaIndex = index;

            // Check whether chiklds are greater, if yes then store it
            if (leftIndex <= size && arr[largestKaIndex] < arr[leftIndex])
            {
                largestKaIndex = leftIndex;
            }
            if (rightIndex <= size && arr[largestKaIndex] < arr[rightIndex])
            {
                largestKaIndex = rightIndex;
            }
            
            // No Change
            if (index == largestKaIndex)
            {
                break;
            }
            else
            {
                swap(arr[index], arr[largestKaIndex]);
                index = largestKaIndex;
            }
        }
        return answer; // Deleted Element
    }
};

void heapify(int *arr, int n, int index) // TC = O(Log(n))
{
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;
    int largestKaIndex = index;

    if (leftIndex <= n && arr[leftIndex] > arr[largestKaIndex])
    {
        largestKaIndex = leftIndex;
    }
    if (rightIndex <= n && arr[rightIndex] > arr[largestKaIndex])
    {
        largestKaIndex = rightIndex;
    }

    if (index != largestKaIndex)
    {
        swap(arr[index], arr[largestKaIndex]);
        index = largestKaIndex;
        heapify(arr, n, index);
    }
    // return;
}

// Aftrer n/2 Elements, (n/2 + 1 --> n) are Leaf Node & they are already valid heap
void buildHeap(int arr[], int n) // TC = O(n)
{
    for (int index = n/2; index > 0; index--)
    {
        heapify(arr, n, index);
    }
}
// Build Heap Should be O(nlog(n)) = O(n) * O(log(n))
// But stll it is O(n) for Creation

void heapSort(int arr[], int n)
{
    while(n != 1)
    {
        swap(arr[1], arr[n]); // NOT n-1
        n--;
        heapify(arr, n, 1);
    }
}
// Heap sort takes TC = n(log(n))
// Heapifing(log(n)) for every Element(O(n))

// Array to Heap in TC = O(n)
// Min and Max in Heap TC = O(1)
// deletion and Insertion TC = O(log(n)) -> dut ot Heapification

int main()
{
    Heap hp(6);
    hp.insert(10);
    hp.insert(20);
    hp.insert(5);
    hp.insert(11);
    hp.insert(6);

    hp.printHeap();
    
    cout << hp.del() << endl;
    hp.printHeap();
    
    int index = 1;
    hp.arr[index] = 2;
    heapify(hp.arr, hp.size, index);
    hp.printHeap();

    int arr[] = {-1, 5, 10, 15, 20, 25, 12};
    int n = 6;

    buildHeap(arr, 6);
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;
    
    heapSort(arr, n);
    for (int i = 1; i <= 6; i++)
    {
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}