// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int mini = INT_MAX;

        int left = 0;
        int right = 0;
        int sum = 0;
        while (right < nums.size())
        {
            sum += nums[right];
            while (sum >= target && left <= right)
            {
                mini = min(mini, right - left + 1);
                sum -= nums[left];
                left++;
            }
            right++;
        }
        if (mini == INT_MAX)
        {
            return 0;
        }
        return mini;
    }
};