// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        if (n < m)
        {
            return {};
        }
        vector<int> pat(26, 0);
        vector<int> win(26, 0);

        for (int i = 0; i < m; i++)
        {
            win[s[i] - 'a']++;
            pat[p[i] - 'a']++;
        }

        vector<int> ans;
        if (pat == win)
        {
            ans.push_back(0);
        }
        for (int i = m; i < n; i++)
        {
            win[s[i - m] - 'a']--;
            win[s[i] - 'a']++;
            if (pat == win)
            {
                ans.push_back(i - m + 1);
            }
        }
        return ans;
    }
};