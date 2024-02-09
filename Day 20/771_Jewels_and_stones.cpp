// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_map<char, int> mp;
        for (auto it : stones)
        {
            mp[it]++;
        }
        int cnt = 0;
        for (auto it : jewels)
        {
            if (mp.find(it) != mp.end())
            {
                cnt += mp[it];
            }
        }
        return cnt;
    }
};