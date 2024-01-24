// TC -O(n)
// SC - O(n)
class Solution
{
private:
    void f(vector<int> &nums, vector<vector<int>> &ans, int ind)
    {
        if (ind == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            f(nums, ans, ind + 1);
            swap(nums[i], nums[ind]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        f(nums, ans, 0);
        return ans;
    }
};