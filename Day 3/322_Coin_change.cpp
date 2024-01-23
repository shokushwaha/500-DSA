// TC - O(n^m)
// SC - I(n^m)
class Solution
{
private:
    vector<vector<int>> dp;

public:
    int coinChange(vector<int> &coins, int amount)
    {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        for (int i = 0; i <= amount; i++)
        {
            if (i % coins[0] == 0)
            {
                dp[0][i] = i / coins[0];
            }
            else
            {
                dp[0][i] = 1e9;
            }
        }

        for (int i = 1; i < coins.size(); i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                int notTake = dp[i - 1][j];

                int take = 1e9;
                if (coins[i] <= j)
                {
                    take = 1 + dp[i][j - coins[i]];
                }
                dp[i][j] = min(take, notTake);
            }
        }
        int ans = dp[coins.size() - 1][amount];

        if (ans >= 1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};