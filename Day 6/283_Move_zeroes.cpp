// TC - O(n)
// SC - O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (nums[right] != 0)
            {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};