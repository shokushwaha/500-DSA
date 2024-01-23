// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string minWindow(string s, string t)
    {
        string ans = "";
        unordered_map<char, int> mp;
        for (auto it : t)
        {
            mp[it]++;
        }

        int reqChars = mp.size();
        int minLen = INT_MAX;
        int minStart = -1;
        unordered_map<char, int> window;
        int start = 0;
        int end = 0;

        while (end < s.size())
        {
            window[s[end]]++;

            if (window[s[end]] == mp[s[end]])
            {
                reqChars--;
            }

            while (reqChars == 0)
            {
                if (end - start + 1 < minLen)
                {
                    minLen = end - start + 1;
                    minStart = start;
                }

                window[s[start]]--;
                if (window[s[start]] < mp[s[start]])
                {
                    reqChars++;
                }
                start++;
            }
            end++;
        }

        if (minLen == INT_MAX)
        {
            return "";
        }
        else
        {
            return s.substr(minStart, minLen);
        }
    }
};