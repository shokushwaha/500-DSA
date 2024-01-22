// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vis[row][col] = 1;
        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, vis, grid);
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    cnt++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return cnt;
    }
};