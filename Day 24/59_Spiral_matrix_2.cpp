// TC - O(n*m)
// SC - O(1)
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int rowStart = 0;
        int rowEnd = n - 1;
        int colStart = 0;
        int colEnd = n - 1;

        int cnt = 1;

        while (cnt <= n * n)
        {
            for (int col = colStart; col <= colEnd; col++)
            {
                matrix[rowStart][col] = cnt;
                cnt++;
            }
            rowStart++;

            for (int row = rowStart; row <= rowEnd; row++)
            {
                matrix[row][colEnd] = cnt;
                cnt++;
            }
            colEnd--;

            for (int col = colEnd; col >= colStart; col--)
            {
                matrix[rowEnd][col] = cnt;
                cnt++;
            }
            rowEnd--;

            for (int row = rowEnd; row >= rowStart; row--)
            {
                matrix[row][colStart] = cnt;
                cnt++;
            }
            colStart++;
        }
        return matrix;
    }
};