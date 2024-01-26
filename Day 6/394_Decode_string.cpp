// TC - O(n)
// SC - O(n)
class Solution
{
public:
    string decodeString(string s)
    {
        stack<int> numStack;
        stack<string> charStack;

        string ans = "";
        int num = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = 10 * num + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                charStack.push(ans);
                ans = "";
                numStack.push(num);
                num = 0;
            }
            else if (s[i] == ']')
            {
                string temp = ans;
                ans = charStack.top();
                charStack.pop();

                int times = numStack.top();
                numStack.pop();
                while (times--)
                {
                    ans += temp;
                }
            }
            else
            {
                ans += s[i];
            }
        }
        return ans;
    }
};