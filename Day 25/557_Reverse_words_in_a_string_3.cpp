// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
            while (i < s.size() && s[i] != ' ')
            {
                st.push(s[i]);
                i++;
            }
            string temp = "";
            while (!st.empty())
            {
                temp += st.top();
                st.pop();
            }
            ans += temp + " ";
        }
        ans.pop_back();
        return ans;
    }
};