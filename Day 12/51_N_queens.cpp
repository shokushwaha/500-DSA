// TC - O(n*n )
// SC - O(n*n)
class Solution
{
private:
    bool isSafe(int row, int col, vector<string> &board, int n)
    {
        int x = row;
        int y = col;

        while (col >= 0)
        {
            if (board[row][col--] == 'Q')
            {
                return false;
            }
        }

        row = x;
        col = y;
        while (row >= 0 && col >= 0)
        {
            if (board[row--][col--] == 'Q')
            {
                return false;
            }
        }

        row = x;
        col = y;
        while (row < n && col >= 0)
        {
            if (board[row++][col--] == 'Q')
            {
                return false;
            }
        }

        return true;
    }
    void f(int n, vector<vector<string>> &ans, vector<string> &board, int col)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col, board, n))
            {
                board[row][col] = 'Q';
                f(n, ans, board, col + 1);
                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        f(n, ans, board, 0);
        return ans;
    }
};