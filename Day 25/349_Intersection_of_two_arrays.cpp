// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;

        for (auto it : nums1)
        {
            mp[it] = 1;
        }
        vector<int> ans;

        for (auto it : nums2)
        {
            if (mp.find(it) != mp.end())
            {
                ans.push_back(it);
                mp.erase(it);
            }
        }
        return ans;
    }
};