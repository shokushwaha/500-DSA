// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        int j = 0;
        while (j < nums.size())
        {
            if (nums[j] != val)
            {
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;
    }
};