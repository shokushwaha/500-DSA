// TC - O(n*n)
// SC - O(n)
class Solution
{
private:
    vector<int> dp;
    int f(int n)
    {
        if (n == 0)
        {
            return 0;
        }
        if (dp[n] != -1)
        {
            return dp[n];
        }
        int mini = INT_MAX;
        for (int i = 1; i * i <= n; i++)
        {
            int ans = 1 + numSquares(n - i * i);
            mini = min(mini, ans);
        }
        return dp[n] = mini;
    }

public:
    int numSquares(int n)
    {
        dp.resize(10001, -1);
        return f(n);
    }
};