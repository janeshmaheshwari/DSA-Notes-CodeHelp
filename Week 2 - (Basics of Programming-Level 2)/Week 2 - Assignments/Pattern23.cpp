#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size for Pascal's Triangle Pattern\n=> ";
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        int count = 1;
        for (int col = 1; col <= row; col++)
        {
            cout << count << " ";
            count = count * (row - col)/col;
        }
        cout << endl;
    }

    return 0;
}