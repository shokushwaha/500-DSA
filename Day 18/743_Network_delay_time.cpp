// TC - O(ElogV)
// SC - O(E)
class Solution
{
private:
    typedef pair<int, int> P;

public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        vector<P> adj[n + 1];

        for (auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        vector<int> dis(n + 1, INT_MAX);

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, k});
        dis[k] = 0;

        while (!pq.empty())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int dist = it.second;

                if (dist + wt < dis[adjNode])
                {
                    dis[adjNode] = dist + wt;
                    pq.push({dis[adjNode], adjNode});
                }
            }
        }
        int maxi = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (dis[i] == INT_MAX)
            {
                return -1;
            }
            maxi = max(maxi, dis[i]);
        }
        return maxi;
    }
};