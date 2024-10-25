#include <iostream>
#include <vector>

using namespace std;

/*
STL = Standard Template Library :-

1.  Static Array --> Static Memory Allocation
eg: int arr[5]

2.  Dynamic Array --> Dynamic Array Allocation
eg: int n;
    cin >> n;
    int * arr = new int[n]
+----------------+----+
|Capacity        |Size|
|(Always Doubles)|    |
+----------------+----+
|1               |1   |
|2(Memory Full)  |2   |
|4(Double up)    |3   |
+----------------+----+
*/

void Print(vector<int> v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout << endl;
}

void PrintVector(vector<int> v)
{
    cout << "Printing Vector by another Method" << endl;
    for(auto it:v)
    {
        cout << it << " ";
    }
    cout << endl;
} 

int main()
{
    vector<int> v;
    
    // while(1)
    // {
    //     int d;
    //     cout << "Enter the value : ";
    //     cin >> d;
    //     v.push_back(d);
    //     cout << "Capacity : " << v.capacity() << "\nSize : " << v.size() << endl;
    // }

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    Print(v);

    v.pop_back();
    Print(v);

    v.pop_back();
    Print(v);

    vector<int>arr1; //Default with no Data and 0 Size
    Print(arr1);

    vector<int>arr2(5, -1); //Initiate with n Size and with Specific Data
    Print(arr2);

    vector<int>arr3 = {1, 2, 3, 4, 5};
    Print(arr3);

    vector<int>arr4(arr3);
    Print(arr4);

    cout << "Front Element : " << arr4[0] << endl;
    cout << "Front Element : " << arr4.front() << endl;
    cout << "Back Element : " << arr4[arr4.size() - 1] << endl;
    cout << "Back Element : " << arr4.back() << endl;

    PrintVector(arr4);

    return 0;
}