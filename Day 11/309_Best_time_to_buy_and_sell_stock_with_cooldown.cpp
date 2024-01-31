// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    int a = -prices[i] + dp[i + 1][0];
                    int b = dp[i + 1][1];
                    dp[i][buy] = max(a, b);
                }
                else
                {
                    int a = prices[i] + dp[i + 2][1];
                    int b = dp[i + 1][0];
                    dp[i][buy] = max(a, b);
                }
            }
        }
        return dp[0][1];
    }
};