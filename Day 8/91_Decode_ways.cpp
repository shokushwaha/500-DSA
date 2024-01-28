// TC - O(n*n)
// SC - O(n)
class Solution
{
private:
    int t[101];
    int solve(int i, string &s, int &n)
    {
        if (t[i] != -1)
        {
            return t[i];
        }

        if (i == n)
        {
            return t[i] = 1;
        }

        if (s[i] == '0')
        {
            return t[i] = 0;
        }

        int result = solve(i + 1, s, n);

        if (i + 1 < n)
        {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
                result += solve(i + 2, s, n);
        }

        return t[i] = result;
    }

public:
    int numDecodings(string s)
    {
        int n = s.length();

        memset(t, -1, sizeof(t));
        return solve(0, s, n);
    }
};