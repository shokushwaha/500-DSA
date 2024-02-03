// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board)
    {
        vis[row][col] = 1;
        int n = board.size();
        int m = board[0].size();

        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, board);
            }
        }
    }

public:
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1)
                {
                    if (board[i][j] == 'O')
                    {
                        dfs(i, j, vis, board);
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && vis[i][j] == 0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};