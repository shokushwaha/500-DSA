// TC - O(n)
// SC - O(1)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        string ans = "";
        int len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (len < right - left + 1)
                {
                    len = right - left + 1;
                    ans = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                if (len < right - left + 1)
                {
                    len = right - left + 1;
                    ans = s.substr(left, right - left + 1);
                }
                left--;
                right++;
            }
        }
        return ans;
    }
};