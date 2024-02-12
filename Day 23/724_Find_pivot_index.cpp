// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int sum = 0;
        for (auto it : nums)
        {
            sum += it;
        }
        int cs = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int ls = cs;
            int rs = sum - cs - nums[i];

            if (ls == rs)
            {
                return i;
            }
            cs += nums[i];
        }
        return -1;
    }
};