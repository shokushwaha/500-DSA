// TC - O(n*n)
// SC - O(n)
class Solution
{
public:
    bool isPalindrome(string &s, int left, int right)
    {
        while (left < right)
            if (s[left++] != s[right--])
                return false;
        return true;
    }
    int fn(string &s, int n, int ind, vector<int> &dp)
    {
        if (ind == n)
            return -1;
        if (dp[ind] != -1)
            return dp[ind];
        int mini = 1e9;
        for (int i = ind; i < n; i++)
        {
            if (isPalindrome(s, ind, i))
            {
                int cut = 1 + fn(s, n, i + 1, dp);
                mini = min(mini, cut);
            }
        }
        return dp[ind] = mini;
    }
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n, -1);
        return fn(s, n, 0, dp);
    }
};