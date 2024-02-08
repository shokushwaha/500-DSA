// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (k <= 1)
        {
            return 0;
        }
        int answer = 0;
        int currentsum = 1;
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            currentsum *= nums[right];
            while (currentsum >= k)
            {
                currentsum /= nums[left++];
            }
            answer += right - left + 1;
        }
        return answer;
    }
};