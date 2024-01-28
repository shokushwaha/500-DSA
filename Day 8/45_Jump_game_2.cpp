// TC - O(n*n)
// SC - O(n)
class Solution
{
public:
    int recall(vector<int> &nums, int ind, vector<int> &dp)
    {
        if (ind >= nums.size() - 1)
            return 0;
        if (dp[ind] != 0)
            return dp[ind];
        int ans = 10000;
        for (int i = ind + 1; i <= ind + nums[ind]; i++)
        {
            int pick = 1 + recall(nums, i, dp);
            ans = min(ans, pick);
        }
        return dp[ind] = ans;
    }
    int jump(vector<int> &nums)
    {
        if (nums.size() == 2)
            return 1;
        vector<int> dp(nums.size(), 0);
        int mans = recall(nums, 0, dp);
        return mans;
    }
};