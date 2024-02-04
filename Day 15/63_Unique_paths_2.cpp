// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    vector<vector<int>> dp;

public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        dp.resize(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 && j == 0) || obstacleGrid[i][j] == 1)
                {
                    continue;
                }

                int up = 0;
                if (i - 1 >= 0)
                {
                    up = dp[i - 1][j];
                }

                int left = 0;
                if (j - 1 >= 0)
                {
                    left = dp[i][j - 1];
                }

                dp[i][j] = up + left;
            }
        }
        return dp[m - 1][n - 1];
    }
};