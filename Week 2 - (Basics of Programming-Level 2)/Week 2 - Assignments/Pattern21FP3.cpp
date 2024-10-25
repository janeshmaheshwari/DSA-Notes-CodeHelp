#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Numbers Between Vertical Stars Triangle\n=> ";
    cin >> n;

    for (int row = 0; row < n + 2; row++)
    {
        for (int col = 0; col < n+2; col++)
        {
            if (row <= (n+1)/2 && col <= 2*row)
            {
                if (col == 0 || col == 2*row)
                {
                    cout << "* ";
                }
                else if (col <= row)
                {
                    cout << col << " ";
                }
                else
                {
                    cout << 2*row - col << " ";
                }
            }
            else if (col <= 2*n - 2*row + 2 && row > (n+1)/2)
            {
                if (col == 0 || col == 2*n - 2*row + 2)
                {
                    cout << "* ";
                }
                else if (col <= n - row + 1)
                {
                    cout << col << " ";
                }
                else
                {
                    cout << 2*n - 2*row + 2 - col << " ";
                }
            }    
        }
        cout << endl;
    }

    return 0;
}