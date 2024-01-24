// TC - O(2^n)
// SC - O(n)
class Solution
{
private:
    void f(vector<int> &nums, int tar, vector<vector<int>> &ans, vector<int> &temp, int ind)
    {
        if (ind == nums.size())
        {
            if (tar == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        f(nums, tar, ans, temp, ind + 1);

        if (nums[ind] <= tar)
        {
            temp.push_back(nums[ind]);
            f(nums, tar - nums[ind], ans, temp, ind);
            temp.pop_back();
        }

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1])
        {
            ind++;
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates, target, ans, temp, 0);
        return ans;
    }
};