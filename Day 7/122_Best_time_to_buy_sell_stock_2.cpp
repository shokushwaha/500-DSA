// TC - O(n*n)
// SC - O(n*n)
class Solution
{
private:
    vector<vector<int>> dp;

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buy = 1;

        dp.resize(n + 1, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                if (buy)
                {
                    int willBuy = -prices[i] + dp[i + 1][0];
                    int willNotBuy = dp[i + 1][1];

                    dp[i][buy] = max(willBuy, willNotBuy);
                }
                else
                {
                    int willSell = prices[i] + dp[i + 1][1];
                    int willNotSell = dp[i + 1][0];

                    dp[i][buy] = max(willSell, willNotSell);
                }
            }
        }
        return dp[0][1];
    }
};