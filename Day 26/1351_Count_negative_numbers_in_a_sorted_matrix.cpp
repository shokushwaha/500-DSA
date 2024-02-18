// TC - O(nlogn)
// SC - O(1)
class Solution
{
public:
    int countNegatives(vector<vector<int>> &g)
    {
        int ans = 0;
        for (auto &i : g)
        {
            int m = i.size();
            int ind = upper_bound(i.rbegin(), i.rend(), -1) - i.rbegin();
            ans += (ind);
        }

        return ans;
    }
};