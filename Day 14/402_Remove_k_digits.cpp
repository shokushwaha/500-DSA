// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        stack<char> st;
        for (char c : num)
        {
            while (!st.empty() && k > 0 && st.top() > c)
            {
                k--;
                st.pop();
            }
            if (!st.empty() || c != '0')
                st.push(c);
        }

        while (!st.empty() && k > 0)
            st.pop(), k--;
        string ans = "";
        while (!st.empty())
            ans += st.top(), st.pop();
        reverse(ans.begin(), ans.end());
        return ans.empty() ? "0" : ans;
    }
};