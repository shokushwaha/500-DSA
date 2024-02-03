// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<string> wordBreak(string s, vector<string> &wordDict)
    {
        unordered_set<string> set;
        vector<string> res;
        for (auto word : wordDict)
            set.insert(word);

        string curr = "";
        findHelper(0, s, curr, set, res);
        return res;
    }

    void findHelper(int ind, string s, string curr, unordered_set<string> set, vector<string> &res)
    {
        if (ind == s.length())
        {
            curr.pop_back();
            res.push_back(curr);
            return;
        }
        string str = "";
        for (int i = ind; i < s.length(); i++)
        {

            str.push_back(s[i]);
            if (set.count(str))
            {
                findHelper(i + 1, s, curr + str + " ", set, res);
            }
        }
    }
};