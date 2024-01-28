// TC - O(nlogn)
// SC - O(n)
#define pb push_back
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int k)
    {

        unordered_map<char, int> hash;
        for (int i = 0; i < tasks.size(); i++)
            hash[tasks[i]]++;

        priority_queue<int> pq;

        for (auto it : hash)
            pq.push(it.second);

        int timer = 0;

        while (!pq.empty())
        {
            vector<int> temp;
            for (int i = 0; i <= k; i++)
            {
                if (!pq.empty())
                {
                    temp.pb(pq.top());
                    pq.pop();
                }
            }

            for (int i = 0; i < temp.size(); i++)
            {
                if (--temp[i] > 0)
                    pq.push(temp[i]);
            }

            timer += pq.empty() ? temp.size() : k + 1;
        }
        return timer;
    }
};