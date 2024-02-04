// TC - O(n*m)
// SC - O(n)
class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 0));
        queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }
        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};
        while (!q.empty())
        {
            int d = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            dis[row][col] = d;

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 1)
                {
                    q.push({d + 1, {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return dis;
    }
};