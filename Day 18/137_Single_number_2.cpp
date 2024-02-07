// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++)
        {
            int zeroCnt = 0;
            int oneCnt = 0;
            for (auto it : nums)
            {
                if ((it >> bit) & 1 == 1)
                {
                    oneCnt++;
                }
                else
                {
                    zeroCnt++;
                }
            }
            if (oneCnt % 3 == 1)
            {
                ans = ans | (1 << bit);
            }
        }
        return ans;
    }
};