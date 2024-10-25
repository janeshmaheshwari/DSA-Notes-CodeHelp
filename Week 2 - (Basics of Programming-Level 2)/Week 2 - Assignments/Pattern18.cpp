#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Solid Half Diamond\n=> ";
    cin >> n;

    for (int row = 0; row < ((2*n) - 1); row++)
    {
        for (int col = 0; col < n; col++)
        {
            if (col <= row && row < n)
            {
                cout << "* ";
            }
            else if (row + col < ((2*n) - 1) && row >= n)
            {
                cout << "* ";
            } 
        }
        cout << endl;
    }     

    return 0;
}