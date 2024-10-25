#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Numeric Palindrome Equilateral Pyramid\n=> ";
    cin >> n;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n + row; col++)
        {
           if (col + row < n - 1)
            {
                cout << " ";
            }
            else if (col < n)
            {
               cout << (row + col) - n + 2;
            }
            else
            {
                cout << n - col + row;
            }
        }
        cout << endl;
    }
    
    return 0;
}