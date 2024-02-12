// TC - O(1)
// SC - O(1)
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};