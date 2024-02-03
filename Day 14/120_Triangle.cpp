// TC - O(n*n)
// SC - O(n*n)
class Solution
{
private:
    vector<vector<int>> dp;

public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        dp.resize(n + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                int down = 1e5;
                if (i + 1 < n)
                {
                    down = dp[i + 1][j];
                }
                int downRight = 1e5;
                if (i + 1 < n && j + 1 < n)
                {
                    downRight = dp[i + 1][j + 1];
                }
                dp[i][j] = triangle[i][j] + min(down, downRight);
            }
        }
        return dp[0][0];
    }
};