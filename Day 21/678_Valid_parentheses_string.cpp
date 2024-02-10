// TC - O(n)
// SC - O(n)
class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> brac, star;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                brac.push(i);
            }
            else if (s[i] == '*')
            {
                star.push(i);
            }
            else
            {
                if (!brac.empty())
                {
                    brac.pop();
                }
                else if (!star.empty())
                {
                    star.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        while (!brac.empty())
        {
            if (star.empty() || star.top() < brac.top())
            {
                return false;
            }
            else
            {
                brac.pop();
                star.pop();
            }
        }
        return true;
    }
};