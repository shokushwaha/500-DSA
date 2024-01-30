// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 1)
        {
            return n;
        }

        int count = 1;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] != nums[i - 1])
            {
                nums[count++] = nums[i];
            }
        }

        return count;
    }
};