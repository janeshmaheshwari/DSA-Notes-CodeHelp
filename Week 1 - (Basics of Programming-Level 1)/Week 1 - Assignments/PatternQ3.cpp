#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Hollow inverted half Pyramid\n=> ";
    cin >> n;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 || col == 0 || row + col == n-1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}