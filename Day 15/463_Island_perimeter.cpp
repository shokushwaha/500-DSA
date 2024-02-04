// TC - O(n*m)
// SC - O(1)
class Solution
{
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    int nbg = 0;
                    if (i + 1 < n && grid[i + 1][j] != 0)
                    {
                        nbg++;
                    }
                    if (i - 1 >= 0 && grid[i - 1][j] != 0)
                    {
                        nbg++;
                    }
                    if (j + 1 < m && grid[i][j + 1] != 0)
                    {
                        nbg++;
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] != 0)
                    {
                        nbg++;
                    }
                    ans += (4 - nbg);
                }
            }
        }
        return ans;
    }
};