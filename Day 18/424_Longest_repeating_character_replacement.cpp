// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int left = 0;
        int right = 0;
        int maxi = 0;
        unordered_map<char, int> mp;
        int len = 0;

        while (right < s.size())
        {
            mp[s[right]]++;
            maxi = max(maxi, mp[s[right]]);

            if (right - left + 1 - maxi > k)
            {
                mp[s[left]]--;
                left++;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};