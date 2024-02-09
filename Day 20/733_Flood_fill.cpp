// TC - O(n*m)
// SC - O(n*m)
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();

        int initialColor = image[sr][sc];

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        q.push({sr, sc});
        image[sr][sc] = color;
        vis[sr][sc] = 1;
        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, -1, 0, 1};

        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nrow = row + delr[i];
                int ncol = col + delc[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && image[nrow][ncol] == initialColor)
                {
                    image[nrow][ncol] = color;
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
        return image;
    }
};