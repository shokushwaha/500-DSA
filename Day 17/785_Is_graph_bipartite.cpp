// TC - O(E+V)
// SC - O(E)
class Solution
{
private:
    bool dfs(int node, int par, int col, vector<int> &color, unordered_map<int, vector<int>> &adj)
    {
        color[node] = col;

        for (auto it : adj[node])
        {
            if (color[it] == -1)
            {
                if (dfs(it, node, !col, color, adj) == false)
                {
                    return false;
                }
            }
            else if (color[it] == color[node])
            {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        unordered_map<int, vector<int>> adj;
        int n = graph.size();
        for (int i = 0; i < n; i++)
        {
            for (auto it : graph[i])
            {
                adj[i].push_back(it);
            }
        }
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++)
        {
            if (color[i] == -1)
            {
                if (dfs(i, -1, 0, color, adj) == false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};