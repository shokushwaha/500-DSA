// TC - O(nlogk)
// SC - O(n)
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (auto it : s)
        {
            mp[it]++;
        }

        priority_queue<pair<int, char>> pq;
        for (auto it : mp)
        {
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty())
        {
            int times = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while (times--)
            {
                ans += ch;
            }
        }
        return ans;
    }
};