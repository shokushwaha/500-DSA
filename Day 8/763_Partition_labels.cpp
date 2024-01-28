// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]] = i;
        }
        vector<int> ans;
        int prev = -1;
        int maxi = -1;
        for (int i = 0; i < s.size(); i++)
        {
            maxi = max(maxi, mp[s[i]]);
            if (i == maxi)
            {
                ans.push_back(maxi - prev);
                prev = i;
            }
        }
        return ans;
    }
};