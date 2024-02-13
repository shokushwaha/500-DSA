// TC - O(n)
// SC - O(n)
class Solution
{
private:
    int operate(string it, int a, int b)
    {
        if (it == "+")
        {
            return a + b;
        }
        else if (it == "-")
        {
            return a - b;
        }
        else if (it == "*")
        {
            return a * b;
        }
        else if (it == "/")
        {
            return a / b;
        }
        return -1;
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (auto it : tokens)
        {
            if (it == "+" || it == "-" || it == "*" || it == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                int res = operate(it, b, a);
                st.push(res);
            }
            else
            {
                st.push(stoi(it));
            }
        }
        return st.top();
    }
};