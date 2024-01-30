// TC - O(n)
// SC - O(1)
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> counter(n + 1);
        for (int i = 1; i <= n; i++)
        {
            counter[i] = counter[i / 2] + i % 2;
        }
        return counter;
    };
};