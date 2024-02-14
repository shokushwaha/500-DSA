// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> mp;
        for (auto i : s)
        {
            mp[i]++;
        }
        int ans = 0;
        bool isOddPresent = false;
        for (auto i : mp)
        {
            if (i.second % 2 == 0)
                ans += i.second;
            else
            {
                ans += i.second - 1;
                isOddPresent = true;
            }
        }
        if (isOddPresent)
            ans += 1;
        return ans;
    }
};