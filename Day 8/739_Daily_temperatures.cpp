// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &nums)
    {
        int n = nums.size() - 1;
        vector<int> ans(nums.size());
        stack<int> st;
        for (int i = n; i >= 0; i--)
        {
            int curr = nums[i];
            while (!st.empty() && nums[st.top()] <= curr)
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = 0;
            }
            else
            {
                ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};