// TC - O(n*m)
// SC - O(n)
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, -1, 0, 1};
        int maxi = 0;
        while (!q.empty())
        {
            int steps = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            maxi = max(maxi, steps);
            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
                {
                    q.push({steps + 1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return maxi;
    }
};