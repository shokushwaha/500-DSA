// TC -O(2^n)
// SC -O(n)
class Solution
{
private:
    void f(vector<string> &combs, vector<string> &ans, string &temp, string digits, int ind)
    {
        if (ind == digits.size())
        {
            ans.push_back(temp);
            return;
        }

        int digit = digits[ind] - '0';
        string comb = combs[digit];

        for (int i = 0; i < comb.size(); i++)
        {
            temp.push_back(comb[i]);
            f(combs, ans, temp, digits, ind + 1);
            temp.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        if (digits == "")
        {
            return {};
        }
        vector<string> combs = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string temp = "";
        f(combs, ans, temp, digits, 0);
        return ans;
    }
};