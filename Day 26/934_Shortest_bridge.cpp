// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    int delr[4] = {1, 0, -1, 0};
    int delc[4] = {0, -1, 0, 1};
    bool isValid(int row, int col, int n, int m)
    {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (isValid(nrow, ncol, n, m) && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, grid, vis);
            }
        }
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    flag = true;
                    dfs(i, j, grid, vis);
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }

        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 1)
                {
                    q.push({0, {i, j}});
                }
            }
        }
        int steps = 0;

        while (!q.empty())
        {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if (isValid(nrow, ncol, n, m) && !vis[nrow][ncol])
                {
                    if (grid[nrow][ncol] == 1)
                    {
                        return steps;
                    }
                    vis[nrow][ncol] = 1;
                    q.push({steps + 1, {nrow, ncol}});
                }
            }
        }
        return -1;
    }
};