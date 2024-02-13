// TC - O(4^(m*n))
// SC - O(m*n)
class Solution
{
public:
    int n, m;

    int ans = 0;

    int st_x, st_y, en_x, en_y;

    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int k;

    void solve(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j, int curr)
    {

        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == -1 || vis[i][j] == true)
            return;

        if (i == en_x and j == en_y)
        {
            if (curr == k)
                ans++;
            return;
        }

        vis[i][j] = true;

        for (auto it : dir)
        {
            int x = it.first + i;
            int y = it.second + j;
            solve(grid, vis, x, y, curr + 1);
        }

        vis[i][j] = false;
    }

    int uniquePathsIII(vector<vector<int>> &grid)
    {
        n = grid.size();
        m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (grid[i][j] == 1)
                {
                    st_x = i;
                    st_y = j;
                }

                else if (grid[i][j] == 2)
                {
                    en_x = i;
                    en_y = j;
                    k++;
                }

                else if (grid[i][j] == 0)
                {
                    k++;
                }
            }
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        solve(grid, vis, st_x, st_y, 0);
        return ans;
    }
};