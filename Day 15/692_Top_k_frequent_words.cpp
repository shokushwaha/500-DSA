// TC - O(nlogn)
// SC - O(n)
#define pp pair<int, string>

class Solution
{
public:
    struct compare
    {
        bool operator()(pair<int, string> &a, pair<int, string> &b)
        {
            if (a.first == b.first)
            {
                return a.second < b.second;
            }

            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string> &s, int k)
    {

        unordered_map<string, int> mp;

        for (int i = 0; i < s.size(); i++)
        {
            mp[s[i]]++;
        }

        priority_queue<pp, vector<pp>, compare> pq;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pp t = {it->second, it->first};

            pq.push(t);

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<string> res;

        while (!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};