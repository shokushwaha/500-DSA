// TC - O(V+E)
// SC - O(V)
class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {

        int n = graph.size();

        vector<int> adj[n];
        vector<int> indegree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (auto j : graph[i])
            {
                adj[j].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto i : adj[node])
            {
                indegree[i]--;

                if (indegree[i] == 0)
                {
                    q.push(i);
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};