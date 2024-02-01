// TC - O(n*m)
// SC - O(n*m)
class Solution
{
public:
    vector<int> X = {0, 0, +1, -1};
    vector<int> Y = {+1, -1, 0, 0};
    int n, m;
    bool isvalid(int x, int y)
    {
        if (x < 0 || x >= n || y < 0 || y >= m)
            return false;

        return true;
    }
    int DFS(vector<vector<int>> &mat, int x, int y, vector<vector<int>> &dp)
    {
        int count = 0;
        if (dp[x][y] != -1)
            return dp[x][y];

        for (int i = 0; i < 4; i++)
        {
            int nx = x + X[i], ny = y + Y[i];
            if (isvalid(nx, ny) && mat[x][y] < mat[nx][ny])
                count = max(count, 1 + DFS(mat, nx, ny, dp));
        }
        return dp[x][y] = count;
    }
    int longestIncreasingPath(vector<vector<int>> &mat)
    {
        n = mat.size();
        m = mat[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                ans = max(ans, DFS(mat, i, j, dp));
        }
        return ans + 1;
    }
};