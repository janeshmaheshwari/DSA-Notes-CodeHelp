#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>> arr(5, vector<int>(10,0));

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>>brr;

    vector<int> vec1(10,1);
    vector<int> vec2(8,0);
    vector<int> vec3(5,1);
    vector<int> vec4(9,0);
    vector<int> vec5(7,1);

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    for (int i = 0; i < brr.size(); i++)
    {
        for (int j = 0; j < brr[i].size(); j++)
        {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}