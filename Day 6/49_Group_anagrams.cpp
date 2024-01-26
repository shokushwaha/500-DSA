// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto it : strs)
        {
            string x = it;
            sort(begin(it), end(it));
            mp[it].push_back(x);
        }
        vector<vector<string>> ans;
        for (auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};