// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string ans = "";

        for (int i = 0; i < s.size(); i++)
        {
            while (i < s.size() && s[i] == ' ')
            {
                i++;
            }
            if (i >= s.size())
            {
                break;
            }
            string temp = "";
            while (i < s.size() && s[i] != ' ')
            {
                temp += s[i];
                i++;
            }
            st.push(temp);
        }

        while (!st.empty())
        {
            ans += st.top() + ' ';
            st.pop();
        }
        ans.pop_back();
        return ans;
    }
};