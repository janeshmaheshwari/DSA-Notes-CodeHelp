#include<algorithm>
#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int> v)
{
    cout << "Printing 1D Vector :-" << endl;
    for(auto it:v)
    {
        cout << it << " ";
    }
    cout << endl;
}

void Print2DVector(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void BubbleSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (v[j] > v[j+1])
            {
                swap(v[j], v[j+1]);
            } 
        }
    }
}

void SelectionSort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        int MinIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] < v[MinIndex])
            {
                MinIndex = j;
            }
        }
        swap(v[i], v[MinIndex]);
    }
}

void InsertionSort(vector<int>& v)
{
    int n = v.size();
    for (size_t i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j-- ;
        }
        v[j + 1] = key; //Insertion
    }
}

//Coustom Comparator :-

bool mycomp(int &a, int &b)
{
    return a > b;
}

bool mycompfor1stIndex(vector<int> &a, vector <int> &b)
{
    return a[1] < b[1]; //Increasing Order
    // return a[1] > b[1]; //Decreasing Order
}

int main()
{
    // vector<int> arr = {4, 5, 2, 3, 1};
    // PrintVector(arr);
    // BubbleSort(arr);
    // PrintVector(arr);

    // vector<int> brr = {4, 5, 2, 3, 1};
    // PrintVector(brr);
    // SelectionSort(brr);
    // PrintVector(brr);

    // vector<int> crr = {4, 5, 2, 3, 1};
    // PrintVector(crr);
    // InsertionSort(crr);
    // PrintVector(crr);

    //Coustom Comparator :-

    //Increasing Order Sorting
    // vector<int> drr = {4, 5, 2, 3, 1};
    // PrintVector(drr);
    // sort(drr.begin(), drr.end());
    // PrintVector(drr);
    
    //Decreasing Order Sorting
    // vector<int> err = {4, 5, 2, 3, 1};
    // PrintVector(err);
    // sort(err.begin(), err.end(), mycomp);
    // PrintVector(err);

    vector<vector<int>> v;
    int n;
    cout << "Enter thye size for 2D Vector : ";
    cin >> n; //5
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cout << "Enter the 2 Values\n=> ";
        cin >> a >> b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    } //(1, 44), (0, 55), (0, 22), (0, 11), (2, 33)
    cout << "Here is the Vector" << endl;
    Print2DVector(v);
    cout << "Sortred by 1st Index" << endl;
    sort(v.begin(), v.end(), mycompfor1stIndex);
    Print2DVector(v);

    return 0;
}