// TC - O(n)
// SC - O(1)
class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int ind = -1;
        int n = nums.size();

        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            reverse(begin(nums), end(nums));
            return;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] > nums[ind])
            {
                swap(nums[i], nums[ind]);
                break;
            }
        }
        sort(begin(nums) + ind + 1, end(nums));
    }
};