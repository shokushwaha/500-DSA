// TC - O(2^n)
// SC - O(n)
class Solution
{
private:
    void solve(vector<int> &nums, int ind, set<vector<int>> &st)
    {
        if (ind == nums.size())
        {
            st.insert(nums);
            return;
        }

        for (int i = ind; i < nums.size(); i++)
        {
            swap(nums[i], nums[ind]);
            solve(nums, ind + 1, st);
            swap(nums[i], nums[ind]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        set<vector<int>> st;
        solve(nums, 0, st);
        for (auto it : st)
            ans.push_back(it);
        return ans;
    }
};