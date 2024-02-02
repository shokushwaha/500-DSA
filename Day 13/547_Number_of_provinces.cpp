// TC - O(n*n)
// SC _O(n)
class Solution
{
private:
    void dfs(int node, int par, vector<int> adj[], vector<int> &vis)
    {
        if (node == par)
        {
            return;
        }
        vis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, node, adj, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {

        int n = isConnected.size();
        vector<int> adj[n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis);
                cnt++;
            }
        }
        return cnt;
    }
};