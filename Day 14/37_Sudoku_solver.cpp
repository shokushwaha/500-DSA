// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    bool isSafe(vector<vector<char>> &board, char ch, int row, int col)
    {
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == ch)
            {
                return false;
            }
            if (board[row][i] == ch)
            {
                return false;
            }
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>> &board)
    {
        int n = board.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char num = '1'; num <= '9'; num++)
                    {
                        if (isSafe(board, num, i, j) == true)
                        {
                            board[i][j] = num;

                            if (solve(board) == true)
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }
};