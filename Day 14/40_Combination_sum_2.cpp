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

        if (nums[ind] <= tar)
        {
            temp.push_back(nums[ind]);
            f(nums, tar - nums[ind], ans, temp, ind + 1);
            temp.pop_back();
        }

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1])
        {
            ind++;
        }

        f(nums, tar, ans, temp, ind + 1);
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(begin(candidates), end(candidates));
        vector<vector<int>> ans;
        vector<int> temp;
        f(candidates, target, ans, temp, 0);
        return ans;
    }
};