// TC - O(V+E)
// SC - O(n)
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto it : flights)
        {
            int u = it[0];
            int v = it[1];
            int x = it[2];
            adj[u].push_back({v, x});
        }
        vector<int> dis(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        dis[src] = 0;
        while (!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second.first;
            int d = q.front().second.second;
            q.pop();

            if (steps > k)
            {
                continue;
            }

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int dist = it.second;

                if (d + dist < dis[adjNode])
                {
                    dis[adjNode] = d + dist;
                    q.push({steps + 1, {adjNode, dis[adjNode]}});
                }
            }
        }
        if (dis[dst] == INT_MAX)
        {
            return -1;
        }
        return dis[dst];
    }
};