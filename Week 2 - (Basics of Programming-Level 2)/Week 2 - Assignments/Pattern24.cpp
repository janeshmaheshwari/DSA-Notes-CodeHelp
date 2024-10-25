#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Butterfly Pattern\n=> ";
    cin >> n;

    for (int row = 0; row < 2*n; row++)
    {
        for (int col = 0; col < 2*n; col++)
        {
            if (row < n)
            {
                if (col <= row)
                {
                    cout << "* ";
                }
                else if (col + row >= (2*n) - 1)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }
            else
            {
                if (col + row <= (2*n) - 1)
                {
                    cout << "* ";
                }
                else if (col >= row)
                {
                    cout << "* ";
                }
                else
                {
                    cout << "  ";
                }
            }    
        }
        cout << endl;
    }

    return 0;
}