// TC - O(n*k)
// SC - O(n*k)
class Solution
{
private:
    vector<vector<vector<int>>> dp;

public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();

        dp.resize(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int l = 0; l <= k; l++)
                {
                    if (l == 0)
                    {
                        continue;
                    }

                    if (buy)
                    {
                        int willBuy = -prices[i] + dp[i + 1][0][l];
                        int willNotBuy = dp[i + 1][1][l];

                        dp[i][buy][l] = max(willBuy, willNotBuy);
                    }
                    else
                    {
                        int willSell = prices[i] + dp[i + 1][1][l - 1];
                        int willNotSell = dp[i + 1][0][l];

                        dp[i][buy][l] = max(willSell, willNotSell);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};