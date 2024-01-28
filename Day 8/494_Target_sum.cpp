// TC - O(2^n)
// SC - O(n)
class Solution
{
public:
    int fun(int i, int n, int target, vector<int> &nums)
    {
        if (i == n)
        {
            if (target == 0)
                return 1;
            else
                return 0;
        }

        int left = fun(i + 1, n, target + nums[i], nums);
        int right = fun(i + 1, n, target - nums[i], nums);
        return right + left;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return fun(0, nums.size(), target, nums);
    }
};