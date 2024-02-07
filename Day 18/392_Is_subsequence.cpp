// TC - O(n *m)
// SC - O(n*m)
class Solution
{
private:
    vector<vector<int>> dp;
    bool f(string s, string t, int ind1, int ind2)
    {
        if (ind1 < 0)
        {
            return true;
        }
        if (ind2 < 0)
        {
            return false;
        }
        if (dp[ind1][ind2] != -1)
        {
            return dp[ind1][ind2];
        }
        if (s[ind1] == t[ind2])
        {
            return dp[ind1][ind2] = f(s, t, ind1 - 1, ind2 - 1);
        }
        else
        {
            return dp[ind1][ind2] = f(s, t, ind1, ind2 - 1);
        }
    }

public:
    bool isSubsequence(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        dp.resize(n, vector<int>(m, -1));
        return f(s, t, n - 1, m - 1);
    }
};