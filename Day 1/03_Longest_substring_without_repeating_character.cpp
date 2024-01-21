// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> mp;
        int len = 0;

        int left = 0;
        int right = 0;
        while (right < s.size())
        {
            if (mp.find(s[right]) != mp.end())
            {
                left = max(left, mp[s[right]] + 1);
            }
            len = max(len, right - left + 1);
            mp[s[right]] = right;
            right++;
        }
        return len;
    }
};