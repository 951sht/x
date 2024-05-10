#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    vector<vector<string>> s1;

public:
    void solve(int col, vector<string> &board, vector<int> &leftrow, vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
    {
        if (col == n)
        {
            s1.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                (solve(col + 1, board, leftrow, upperDiagonal, lowerDiagonal, n));
                board[row][col] = '*';
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    void solveNQueens(int n)
    {
        vector<string> board(n, string(n, '*'));
        vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, leftrow, upperDiagonal, lowerDiagonal, n);
        cout << s1.size() << endl;
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 0; j < s1[i].size(); j++)
            {
                cout << s1[i][j] << endl;
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    int n;
    cout << "Enter Board size: ";
    cin >> n;
    s.solveNQueens(n);

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int N;

void printSol(vector<vector<int>> board)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
            {
                cout << "Q ";
            }
            else
            {
                cout << "* ";
            }
        }
        cout << "\n";
    }
}

bool isSafe(int row, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{

    if (rows[row] == true || left_digonals[row + col] == true || Right_digonals[col - row + N - 1] == true)
    {
        return false;
    }

    return true;
}

bool solve(vector<vector<int>> &board, int col, vector<bool> rows, vector<bool> left_digonals, vector<bool> Right_digonals)
{

    if (col >= N)
    {
        return true;
    }

    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col, rows, left_digonals, Right_digonals) == true)
        {
            rows[i] = true;
            left_digonals[i + col] = true;
            Right_digonals[col - i + N - 1] = true;
            board[i][col] = 1;

            if (solve(board, col + 1, rows, left_digonals, Right_digonals) == true)
            {
                return true;
            }

            rows[i] = false;
            left_digonals[i + col] = false;
            Right_digonals[col - i + N - 1] = false;
            board[i][col] = 0;
        }
    }

    return false;
}

int main()
{
    cout << "Enter the no of rows for the square Board : ";
    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));
    vector<bool> rows(N, false);
    vector<bool> left_digonals(2 * N - 1, false);
    vector<bool> Right_digonals(2 * N - 1, false);

    bool ans = solve(board, 0, rows, left_digonals, Right_digonals);

    if (ans == true)
    {
        printSol(board);
    }
    else
    {
        cout << "Solution Does not Exist\n";
    }
}
*/
