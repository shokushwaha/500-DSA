// TC - O(nlogn)
// SC - O(1)
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); i++)
        {
            int j = i + 1;
            int k = nums.size() - 1;
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            {
                i++;
            }
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while (j < k && nums[j - 1] == nums[j])
                    {
                        j++;
                    }
                    while (j < k && nums[k] == nums[k + 1])
                    {
                        k--;
                    }
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return ans;
    }
};