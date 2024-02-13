// TC - O(n)
// SC - O(n)
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        int i = 0;
        int j = 0;

        while (i < pattern.size() && j < s.size())
        {
            string temp = "";
            while (j < s.size() && s[j] != ' ')
            {
                temp += s[j];
                j++;
            }
            if (mp1.find(pattern[i]) != mp1.end() && mp1[pattern[i]] != temp)
            {
                return false;
            }
            if (mp2.find(temp) != mp2.end() && mp2[temp] != pattern[i])
            {
                return false;
            }

            mp1[pattern[i]] = temp;
            mp2[temp] = pattern[i];
            i++;
            j++;
            while (j < s.size() && s[j] == ' ')
            {
                j++;
            }
        }
        if (i < pattern.size() || j < s.size())
        {
            return false;
        }
        return true;
    }
};
