// TC - O(nlogk)
// SC - O(k)
class Solution
{
private:
    double findDis(int x, int y)
    {
        int base = x * x + y * y;
        return sqrt(base);
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        priority_queue<pair<double, pair<int, int>>> pq;

        for (auto it : points)
        {
            double dis = findDis(it[0], it[1]);
            pq.push({dis, {it[0], it[1]}});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};