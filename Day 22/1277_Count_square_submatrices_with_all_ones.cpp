// TC - O(n*m)
// SC - O(n*m)
class Solution
{
public:
    int countSquares(vector<vector<int>> &m)
    {
        int r = m.size();
        int c = m[0].size();
        int count = 0;

        for (int i = 1; i < r; i++)
        {
            for (int j = 1; j < c; j++)
            {
                if (m[i][j] == 1)
                {
                    m[i][j] = min(m[i - 1][j - 1], min(m[i - 1][j], m[i][j - 1])) + 1;
                }
            }
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                count += m[i][j];
            }
        }
        return count;
    }
};