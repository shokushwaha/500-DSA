// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    bool f(int ind, int row, int col, vector<vector<char>> &board, string &word, vector<vector<int>> &vis)
    {
        int n = board.size();
        int m = board[0].size();

        int delr[] = {-1, 0, 1, 0};
        int delc[] = {0, 1, 0, -1};

        if (ind == word.size())
        {
            return true;
        }
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delr[i];
            int ncol = col + delc[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && word[ind] == board[nrow][ncol])
            {
                if (f(ind + 1, nrow, ncol, board, word, vis))
                {
                    return true;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word[0])
                {
                    vis[i][j] = 1;
                    if (f(1, i, j, board, word, vis))
                    {
                        return true;
                    }
                    vis[i][j] = 0;
                }
            }
        }
        return false;
    }
};