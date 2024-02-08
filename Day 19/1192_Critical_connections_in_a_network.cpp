// TC - O(E+V)
// SC - O(E)
class Solution
{
private:
    int timer = 0;
    vector<int> low;
    vector<int> tin;
    vector<int> vis;

    void f(vector<int> adj[], vector<vector<int>> &ans, int node, int par)
    {
        vis[node] = 1;
        low[node] = tin[node] = timer++;

        for (auto it : adj[node])
        {
            if (it == par)
            {
                continue;
            }
            if (!vis[it])
            {
                f(adj, ans, it, node);
                low[node] = min(low[node], low[it]);

                if (low[it] > tin[node])
                {
                    ans.push_back({it, node});
                }
            }
            else
            {
                low[node] = min(low[node], low[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {
        vector<int> adj[n];

        for (auto it : connections)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        tin.resize(n);
        low.resize(n);
        vis.resize(n, 0);
        vector<vector<int>> ans;
        f(adj, ans, 0, -1);
        return ans;
    }
};