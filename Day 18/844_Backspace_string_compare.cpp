// TC - O(n+m)
// SC - O(n+m)
class Solution
{
private:
    string find(string s)
    {
        string ans = "";
        for (auto it : s)
        {
            if (it == '#')
            {
                if (ans.size() > 0)
                {
                    ans.pop_back();
                }
            }
            else
            {
                ans += it;
            }
        }
        return ans;
    }

public:
    bool backspaceCompare(string s, string t)
    {
        string first = find(s);
        string second = find(t);
        return first == second;
    }
};