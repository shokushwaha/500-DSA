// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    vector<vector<int>> dp;
    bool isAllStars(string str, int ind)
    {
        for (int i = 1; i <= ind; i++)
        {
            if (str[i - 1] != '*')
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        dp.resize(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = 1;
        for (int j = 1; j <= m; j++)
        {
            dp[0][j] = isAllStars(p, j);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[n][m];
    }
};