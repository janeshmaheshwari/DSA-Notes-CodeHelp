#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the size for Flipped Solid Diamond\n=> ";
    cin >> num;
    int n = num/2;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= 2*n; col++)
        {
            if (row + col < n)
            {
                cout << "* ";
            }
            else if (col <= n + row)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col <= 2*n; col++)
        {
            if (col <= row)
            {
                cout << "* ";
            }
            else if (col + row < 2*n)
            {
                cout << "  ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << endl;
    }
    
    return 0;
}