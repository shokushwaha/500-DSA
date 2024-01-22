// TC - O(n)
// SC - O(n)
class Solution
{
private:
    vector<int> dp;
    int f(vector<int> &nums, int ind)
    {
        if (ind >= nums.size())
        {
            return 0;
        }
        if (dp[ind] != -1)
        {
            return dp[ind];
        }
        int take = nums[ind] + f(nums, ind + 2);
        int notTake = f(nums, ind + 1);
        return dp[ind] = max(take, notTake);
    }

public:
    int rob(vector<int> &nums)
    {
        dp.resize(nums.size(), -1);
        return f(nums, 0);
    }
};