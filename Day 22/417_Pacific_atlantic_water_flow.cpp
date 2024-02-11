// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    void dfs(vector<vector<int>> &heights, int row, int col, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        int n = heights.size();
        int m = heights[0].size();

        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && heights[nrow][ncol] >= heights[row][col] && !vis[nrow][ncol])
            {
                dfs(heights, nrow, ncol, vis);
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pVis(n, vector<int>(m, 0));
        vector<vector<int>> aVis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == 0 || j == 0)
                {
                    dfs(heights, i, j, pVis);
                }
                if (i == n - 1 || j == m - 1)
                {
                    dfs(heights, i, j, aVis);
                }
            }
        }
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (aVis[i][j] == 1 && pVis[i][j] == 1)
                {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};