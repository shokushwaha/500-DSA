// TC - O(2^n)
// SC - O(2^n)
class Solution
{
private:
    void f(int n, int openCnt, int endCnt, string temp, vector<string> &ans)
    {
        if (temp.size() == 2 * n)
        {
            ans.push_back(temp);
            return;
        }
        if (openCnt < n)
        {
            f(n, openCnt + 1, endCnt, temp + "(", ans);
        }
        if (endCnt < openCnt)
        {
            f(n, openCnt, endCnt + 1, temp + ")", ans);
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string temp = "";

        int openCnt = 0;
        int endCnt = 0;

        f(n, openCnt, endCnt, temp, ans);
        return ans;
    }
};