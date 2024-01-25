// TC - O(2^n)
// SC - O(n)
class Solution
{
private:
    void f(vector<int> &nums, vector<int> &temp, vector<vector<int>> &ans, int ind)
    {
        if (ind == nums.size())
        {
            ans.push_back(temp);
            return;
        }
        f(nums, temp, ans, ind + 1);

        while (ind + 1 < nums.size() && nums[ind] == nums[ind + 1])
        {
            ind++;
        }
        temp.push_back(nums[ind]);
        f(nums, temp, ans, ind + 1);
        temp.pop_back();
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> temp;
        vector<vector<int>> ans;
        f(nums, temp, ans, 0);
        return ans;
    }
};