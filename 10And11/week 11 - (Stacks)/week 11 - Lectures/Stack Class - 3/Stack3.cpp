#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextSmallerElement(int* arr, int size, vector<int>& ans)
{
    stack<int> st;
    st.push(-1);

    for (int i = size-1; i >= 0; i--)
    {
        int curr = arr[i];

        //Answer find for curr
        while(st.top() >= curr)
        {
            st.pop();
        }

        //Top element is less than curr, store it
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

vector<int> prevSmallerElement(int* arr, int size, vector<int>& ans)
{
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < size; i++) //Reverse Loop
    {
        int curr = arr[i];

        //Answer find for curr
        while(st.top() >= curr)
        {
            st.pop();
        }

        //Top element is less than curr, store it
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}

int main()
{
    int arr1[5] = {8, 4, 6, 2, 3};
    int size1 = 5;
    vector<int> ans1(size1);

    nextSmallerElement(arr1, size1, ans1);
    
    for(auto element : ans1)
    {
        cout << element << " ";
    } cout << endl;


    int arr2[5] = {8, 4, 6, 2, 3};
    int size2 = 5;
    vector<int> ans2(size2);

    prevSmallerElement(arr2, size2, ans2);
    
    for(auto element : ans2)
    {
        cout << element << " ";
    } cout << endl;
    
    return 0;
}