// TC - O(n*m)
// SC - O(1)
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size() - 1;
        int colEnd = matrix[0].size() - 1;

        int cnt = 0;
        int total = matrix.size() * matrix[0].size();

        vector<int> ans;

        while (cnt < total)
        {
            for (int col = colStart; col <= colEnd && cnt < total; col++)
            {
                ans.push_back(matrix[rowStart][col]);
                cnt++;
            }
            rowStart++;
            for (int row = rowStart; row <= rowEnd && cnt < total; row++)
            {
                ans.push_back(matrix[row][colEnd]);
                cnt++;
            }
            colEnd--;
            for (int col = colEnd; col >= colStart && cnt < total; col--)
            {
                ans.push_back(matrix[rowEnd][col]);
                cnt++;
            }
            rowEnd--;
            for (int row = rowEnd; row >= rowStart && cnt < total; row--)
            {
                ans.push_back(matrix[row][colStart]);
                cnt++;
            }
            colStart++;
        }
        return ans;
    }
};