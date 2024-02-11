// TC - O(n*m)
// SC - O(n*m)
class Solution
{
private:
    static bool comp(string &a, string &b)
    {
        return a.size() < b.size();
    }
    bool compareString(string &str1, string &str2)
    {
        if (str1.size() != str2.size() + 1)
            return false;

        int first = 0, second = 0;
        while (first < str1.size())
        {
            if (str1[first] == str2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }

        if (first == str1.size() && second == str2.size())
            return true;

        else
            return false;
    }

public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        sort(begin(words), end(words), comp);
        vector<int> dp(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (compareString(words[i], words[prev]) && dp[i] < 1 + dp[prev])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};