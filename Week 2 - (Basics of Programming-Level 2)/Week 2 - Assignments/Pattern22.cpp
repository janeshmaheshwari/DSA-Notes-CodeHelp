#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Floyd's Triangle\n=> ";
    cin >> n;

    int count = 1;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (col <= row)
            {
                cout << count;
                count ++;
            }
        }
        cout << endl;
    }

    return 0;
}