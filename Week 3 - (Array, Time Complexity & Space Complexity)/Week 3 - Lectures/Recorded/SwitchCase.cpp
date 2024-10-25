#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "Enter the numbers\n=> ";
    cin >> x >> y;
    float ans = 0;
    int op;
    cout << "=> ";
    cin >> op;

    switch (op)
    {
    case 0:
        ans = x+y;
        break;

    case 1:
        ans = x-y;
        break;

    case 2:
        ans = x*y;
        break;

    case 3:
        ans = x/y;
        break;
    
    default:
        cout << "Invalid Input";
        return 0;
    }
    cout << "Your answer is " << ans << endl;

    return 0;
}