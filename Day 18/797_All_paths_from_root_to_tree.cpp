// TC - O(n)
// SC - O(h)
class Solution
{
private:
    void dfs(int node, int n, vector<int> &vis, vector<vector<int>> &ans, vector<int> &temp, vector<vector<int>> &graph)
    {
        if (node == n - 1)
        {
            ans.push_back(temp);
            return;
        }
        vis[node] = 1;
        for (auto it : graph[node])
        {
            if (!vis[it])
            {
                temp.push_back(it);
                dfs(it, n, vis, ans, temp, graph);
                temp.pop_back();
            }
        }
        vis[node] = 0;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(0);
        dfs(0, n, vis, ans, temp, graph);
        return ans;
    }
};