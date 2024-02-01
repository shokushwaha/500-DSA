// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis, int &cnt)
    {
        vis[row][col] = 1;
        cnt++;

        int n = grid.size();
        int m = grid[0].size();

        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1 && !vis[nrow][ncol])
            {
                dfs(nrow, ncol, grid, vis, cnt);
            }
        }
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && !vis[i][j])
                {
                    int cnt = 0;
                    dfs(i, j, grid, vis, cnt);
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi;
    }
};