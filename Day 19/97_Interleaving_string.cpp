// TC - O(n*m)
// SC - O(n*m)
class Solution
{
    bool help(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>> &dp)
    {

        if (i == s1.size() && j == s2.size() && k == s3.size())
        {
            return true;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        bool result1 = false;
        if (i < s1.size() && s1[i] == s3[k])
        {
            result1 = help(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        bool result2 = false;
        if (j < s2.size() && s2[j] == s3[k])
        {
            result2 = help(s1, s2, s3, i, j + 1, k + 1, dp);
        }
        return dp[i][j] = result1 | result2;
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();

        if (m + n != k)
        {
            return false;
        }

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return help(s1, s2, s3, 0, 0, 0, dp);
    }
};