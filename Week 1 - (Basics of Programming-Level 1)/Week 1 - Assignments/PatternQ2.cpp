#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Hollow square\n=> ";
    cin >> n;


    for (int row = 0; row < n; row++)
    {
        if (row == 0 || row == n-1)
        {
            for (int col = 0; col < n; col++)
            {
                cout << "*";
            }
        }

        else
        {
            for (int col = 0; col < n; col++)
            {
                if (col == 0 || col == n-1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
            }      
        }
        cout << endl;
    }


    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (row == 0 || row == n-1 || col == 0 || col == n-1)
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