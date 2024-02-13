// TC - O(2^n)
// SC - O(n)
class Solution
{
private:
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    void f(int k, int tar, vector<int> &temp, vector<vector<int>> &ans, int ind)
    {
        if (ind == nums.size())
        {
            if (temp.size() == k && tar == 0)
            {
                ans.push_back(temp);
            }
            return;
        }

        if (nums[ind] <= tar)
        {
            temp.push_back(nums[ind]);
            f(k, tar - nums[ind], temp, ans, ind + 1);
            temp.pop_back();
        }
        f(k, tar, temp, ans, ind + 1);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        f(k, n, temp, ans, 0);
        return ans;
    }
};