#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Numeric Hollow Half Pyramid\n=> ";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row + 2; col++)
        {
            if (col == 0)
            {
                cout << 1;
            }
            else if (row == n-1 && col < n)
            {
                cout << col + 1;
            }
            else
            {
                if (row > 0 && row < n-1)
                {
                    if (col == row + 1)
                    {
                        cout << row + 1;
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}