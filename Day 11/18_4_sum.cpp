// TC - O(n*nlogn)
// SC - O(1)
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    long long int curr = nums[i];
                    curr += nums[j];
                    curr += nums[left];
                    curr += nums[right];

                    if (curr == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                    else if (curr < target)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                }

                while (j < nums.size() - 1 && nums[j] == nums[j + 1])
                    j++;
            }
            while (i < nums.size() - 1 && nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }
};