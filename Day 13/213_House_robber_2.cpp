// TC - O(n*m)
// SC - O(n*m)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        vector<int> dp1(n - 1, -1);
        vector<int> nums1(nums.begin(), nums.end() - 1);
        int case1 = solve(nums1, dp1, n - 2);

        vector<int> dp2(n - 1, -1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        int case2 = solve(nums2, dp2, n - 2);

        return max(case1, case2);
    }

    int solve(vector<int> &nums, vector<int> &dp, int index)
    {
        if (index == 0)
        {
            return nums[index];
        }
        if (index < 0)
        {
            return 0;
        }
        if (dp[index] != -1)
        {
            return dp[index];
        }
        int left = nums[index] + solve(nums, dp, index - 2);
        int right = solve(nums, dp, index - 1);
        int ans = max(left, right);
        dp[index] = ans;
        return ans;
    }
};