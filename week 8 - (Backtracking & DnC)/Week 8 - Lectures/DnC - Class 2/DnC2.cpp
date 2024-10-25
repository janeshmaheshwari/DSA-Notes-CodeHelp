#include <iostream>
#include <vector>
using namespace std;

void PrintPermutationWrong(string &str, int index)
{
    //Base Case
    if (index >= str.length())
    {
        cout << str << " ";
        return;
    }
    
    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        //Recursion
        PrintPermutationWrong(str, index + 1);
    }
}

void PrintPermutation(string &str, int index)
{
    //Base Case
    if (index >= str.length())
    {
        cout << str << " ";
        return;
    }
    
    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        //Recursion
        PrintPermutation(str, index + 1);
        //Backtracking
        swap(str[index], str[j]);
    }
}

bool isSafe(int x, int y, int maze[][4], int row, int col, vector<vector<bool>> &visited)
{
    //-> Path Closed
    //-> Out of Bound
    //-> Check if Position already visited

    if ((x >= 0 && x < row) && (y >= 0 && y < col) &&
       (maze[x][y] == 1) && (visited[x][y] == false))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>> &visited)
{
    //Base Case :- Destination at row-1 & col-1
    if ((srcx == row - 1) && (srcy == col - 1))
    {
        cout << output << endl;
        return;
    }
    
    //Solving First Case :-

        //Mark Visited
        //Call Recursion
        //Backtracking (Not Visited)

    //UP :-
    int x = srcx - 1;
    int y = srcy;
    if (isSafe(x, y, maze, row, col, visited))
    {
        visited[x][y] = true;
        output.push_back('U');

        printAllPath(maze, row, col, x, y, output, visited);

        output.pop_back();
        visited[x][y] = false;
    }

    //Right:-
    x = srcx;
    y = srcy + 1;
    if (isSafe(x, y, maze, row, col, visited))
    {
        visited[x][y] = true;
        output.push_back('R');

        printAllPath(maze, row, col, x, y, output, visited);

        output.pop_back();
        visited[x][y] = false;
    }

    //Down :-
    x = srcx + 1;
    y = srcy;
    if (isSafe(x, y, maze, row, col, visited))
    {
        visited[x][y] = true;
        output.push_back('D');

        printAllPath(maze, row, col, x, y, output, visited);

        output.pop_back();
        visited[x][y] = false;
    }
    
    //Left :-
    x = srcx;
    y = srcy - 1;
    if (isSafe(x, y, maze, row, col, visited))
    {
        visited[x][y] = true;
        output.push_back('L');

        printAllPath(maze, row, col, x, y, output, visited);

        output.pop_back();
        visited[x][y] = false;
    }
}

int main()
{
    string str = "abc";
    int index = 0;
    // cout << "Without Backtracking :" << endl;
    // PrintPermutationWrong(str, index);
    // cout << endl << "With Backtracking :" << endl;
    // PrintPermutation(str, index);

    int maze[4][4] = 
    {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}
    };
    int row = 4;
    int col = 4;

    int srcx = 0;
    int srcy = 0;
    string output = "";

    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (maze[0][0] == 0)
    {
        cout << "No Path Exists" << endl;
    }
    else
    {
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }

    return 0;
}