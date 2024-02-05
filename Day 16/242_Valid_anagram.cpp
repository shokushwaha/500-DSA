// TC - O(n)
// SC - O(1)
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> fS(26, 0);
        vector<int> fT(26, 0);
        for (auto it : s)
        {
            fS[it - 'a']++;
        }
        for (auto it : t)
        {
            fT[it - 'a']++;
        }
        return fS == fT;
    }
};