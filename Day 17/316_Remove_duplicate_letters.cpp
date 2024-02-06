// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<int> lastInd(26, 0);
        vector<bool> taken(26, false);

        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            lastInd[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];

            if (taken[ch - 'a'] == true)
            {
                continue;
            }

            while (ans.size() && ans.back() > ch && lastInd[ans.back() - 'a'] > i)
            {
                taken[ans.back() - 'a'] = false;
                ans.pop_back();
            }
            ans += ch;
            taken[ch - 'a'] = true;
        }
        return ans;
    }
};