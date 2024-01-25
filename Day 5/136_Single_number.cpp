// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int num = 0;
        for (auto it : nums)
        {
            num ^= it;
        }
        return num;
    }
};