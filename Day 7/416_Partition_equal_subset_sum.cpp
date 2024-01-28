// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    vector<vector<int>> dp;
    bool f(vector<int> &nums, int ind, int tar)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++)
        {
            for (int target = 1; target <= tar; target++)
            {
                int notTake = dp[i - 1][target];
                int take = false;
                if (nums[i] <= target)
                {
                    take = dp[i - 1][target - nums[i]];
                }
                dp[i][target] = take || notTake;
            }
        }
        return dp[n - 1][tar];
    }

public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        if (sum & 1)
        {
            return false;
        }
        dp.resize(nums.size(), vector<int>(sum + 1, 0));
        return f(nums, nums.size() - 1, sum / 2);
    }
};