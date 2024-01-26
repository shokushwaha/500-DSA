// TC - O(nlogk)
// SC - O(k)
class Solution
{
private:
    typedef pair<int, int> P;

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        for (auto it : mp)
        {
            pq.push({it.second, it.first});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};