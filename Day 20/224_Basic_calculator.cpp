// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int calculate(string s)
    {
        int number = 0;
        int sign = 1;
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                number = number * 10 + (s[i] - '0');
            }
            else if (s[i] == '+')
            {
                ans += (number * sign);
                number = 0;
                sign = 1;
            }
            else if (s[i] == '-')
            {
                ans += (number * sign);
                number = 0;
                sign = -1;
            }
            else if (s[i] == '(')
            {
                st.push(ans);
                st.push(sign);
                ans = 0;
                sign = 1;
                number = 0;
            }
            else if (s[i] == ')')
            {
                ans += (sign * number);
                number = 0;
                int top = st.top();
                st.pop();
                ans *= top;
                top = st.top();
                st.pop();
                ans += top;
            }
        }
        ans += (sign * number);
        return ans;
    }
};