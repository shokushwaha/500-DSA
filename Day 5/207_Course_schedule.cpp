// TC -O(N+E)
// SC - O(N)
class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        unordered_map<int, vector<int>> adj;
        for (auto it : prerequisites)
        {
            int a = it[0];
            int b = it[1];
            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            cnt++;

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }
        return cnt == numCourses;
    }
};