// TC - O(2^n)
// SC - O(n)
class Solution
{
public:
    vector<int> diffWaysToCompute(string exp)
    {
        vector<int> ans;
        int n = exp.size();
        for (int i = 0; i < n; i++)
        {
            char c = exp[i];
            if (c == '+' || c == '-' || c == '*')
            {
                vector<int> left = diffWaysToCompute(exp.substr(0, i));
                vector<int> right = diffWaysToCompute(exp.substr(i + 1));
                for (int l : left)
                {
                    for (int r : right)
                    {
                        if (c == '+')
                            ans.push_back(l + r);
                        else if (c == '-')
                            ans.push_back(l - r);
                        else if (c == '*')
                            ans.push_back(l * r);
                    }
                }
            }
        }
        if (ans.empty())
        {
            ans.push_back(atoi(exp.c_str()));
        }
        return ans;
    }
};