// TC - O(n*k)
// SC - O(n*k)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int K = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(K + 1, 0)));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int k = 0; k <= K; k++)
                {
                    if (k == 0)
                    {
                        continue;
                    }
                    else
                    {
                        if (buy)
                        {
                            int a = -prices[i] + dp[i + 1][0][k];
                            int b = dp[i + 1][1][k];
                            dp[i][buy][k] = max(a, b);
                        }
                        else
                        {
                            int a = prices[i] + dp[i + 1][1][k - 1];
                            int b = dp[i + 1][0][k];
                            dp[i][buy][k] = max(a, b);
                        }
                    }
                }
            }
        }
        return dp[0][1][K];
    }
};