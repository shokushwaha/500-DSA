// TC - O(nlogn)
// SC - O(1)
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &a)
    {
        for (auto &x : a)
            x *= x;
        sort(a.begin(), a.end());
        return a;
    }
};