#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Numeric Star Vertical Triangle\n=> ";
    cin >> n;

    int count = 1;

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < ((2*n)-1); col++)
        {
            if (col <= 2*row && row < n)
            {
                if (col%2 == 0)
                {
                    cout << count;
                    count ++;
                }
                else
                {
                    cout << " * ";
                }    
            }   
        }
        cout << endl;
    }

    int start = count - n;

    for (int row = 0; row < n; row++)
    {
        int k = start;

        for (int col = 0; col < ((2*n)-1); col++)
        {
            if (2*row + col < 2*n - 1 && col %2 == 0)
            {
                cout << k;
                k++;
            }
            else if (col < 2*n - 1 - 2*row)
            {
                cout << " * ";
            } 
        }
        start = start - (n - row - 1);
        cout << endl; 
    }

    return 0;
}