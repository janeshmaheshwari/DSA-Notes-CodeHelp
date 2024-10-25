#include <iostream>
using namespace std;

int main()
{
    int num;
    cout << "Enter the size for Hollow Diamond\n=> ";
    cin >> num;
    int n = num/2;

    for (int row = 0; row < n; row++)
    {
        int k = 0;

        for (int col = 0;col < (2*n) - 1; col++)
        {   
            if (row + col < n - 1)
            {
                cout << " ";
            }
            else if (k < (2*row)+1)
            {
                if (k == 0 || k== 2*row)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                k++;
            }
            else
            {
                cout << " ";
            }             
        }
        cout << endl;
    }

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < row; col++)
        {
            cout << " "; 
        }
        for (int col = 0; col < n-row; col++)
        {
            if (col == 0 || col == n-row-1)
            {
                cout << "* ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl ;
    }

    return 0;
}