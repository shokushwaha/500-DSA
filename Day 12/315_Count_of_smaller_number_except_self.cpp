// TC - O(n)
// SSC - O(n)
class Solution
{
public:
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> bucket(1e5, 0);
        for (auto it : nums)
        {
            bucket[it]++;
        }

        for (int i = 1; i < bucket.size(); i++)
        {
            bucket[i] += bucket[i - 1];
        }

        vector<int> ans(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = bucket[nums[i] - 1];
            }
        }
        return ans;
    }
};