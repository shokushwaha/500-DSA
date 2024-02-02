// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    vector<vector<int>> dp;
    int f(int tar, vector<int> &coins, int ind)
    {
        if (tar == 0)
        {
            return 1;
        }
        if (ind == 0)
        {
            return tar % coins[ind] == 0;
        }
        if (dp[ind][tar] != -1)
        {
            return dp[ind][tar];
        }
        int notTake = f(tar, coins, ind - 1);
        int take = 0;
        if (coins[ind] <= tar)
        {
            take = f(tar - coins[ind], coins, ind);
        }
        return dp[ind][tar] = take + notTake;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        return f(amount, coins, coins.size() - 1);
    }
};