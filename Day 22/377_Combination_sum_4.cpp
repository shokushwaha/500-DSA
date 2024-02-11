// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    vector<vector<int>> dp;
    int f(vector<int> &nums, int tar, int ind)
    {
        if (tar == 0)
        {
            return 1;
        }

        if (ind >= nums.size() || tar < 0)
        {
            return 0;
        }

        if (dp[ind][tar] != -1)
        {
            return dp[ind][tar];
        }

        int take = f(nums, tar - nums[ind], 0);
        int notTake = f(nums, tar, ind + 1);
        return dp[ind][tar] = take + notTake;
    }

public:
    int combinationSum4(vector<int> &nums, int target)
    {
        dp.resize(nums.size(), vector<int>(target + 1, -1));
        return f(nums, target, 0);
    }
};