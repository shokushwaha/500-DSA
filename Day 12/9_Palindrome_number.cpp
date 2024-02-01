// TC - O(n)
// SC- O(1)
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x == 0)
        {
            return true;
        }
        int sign = x / abs(x);
        long long int num = x;
        x = abs(x);
        long long int rev = 0;
        while (x)
        {
            long long int rem = x % 10;
            rev = rev * 10 + rem;
            x /= 10;
        }
        if (sign == -1)
        {
            return false;
        }
        return rev == num;
    }
};