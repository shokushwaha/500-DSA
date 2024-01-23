// TC - O(nlogn)
// SC - O(n)
class Solution
{
private:
    unordered_map<int, bool> dp;
    bool f(string str, unordered_set<string> &st, int ind)
    {
        if (ind == str.size())
        {
            return true;
        }
        if (dp.count(ind))
        {
            return dp[ind];
        }
        string temp = "";
        for (int i = ind; i < str.size(); i++)
        {
            temp += str[i];
            if (st.find(temp) != st.end())
            {
                if (f(str, st, i + 1) == true)
                {
                    return dp[ind] = true;
                }
            }
        }
        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> st(begin(wordDict), end(wordDict));
        return f(s, st, 0);
    }
};