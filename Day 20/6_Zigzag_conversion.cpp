// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.empty() || numRows <= 1)
            return s;

        vector<string> str(numRows);

        bool goingDown = false;
        int row = 0;
        for (char c : s)
        {
            str[row] += c;
            if (row == 0 || row == numRows - 1)
                goingDown = !goingDown;
            row += goingDown ? 1 : -1;
        }

        string ans;
        for (const string &row : str)
            ans += row;

        return ans;
    }
};
