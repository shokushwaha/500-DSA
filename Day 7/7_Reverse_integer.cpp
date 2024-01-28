// TC - O(n)
// SC - (1)
class Solution
{
public:
    int reverse(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        long long int sign = x / (abs(x));

        long long int num = abs(x);
        long long int ans = 0;
        while (num)
        {
            long long int dig = num % 10;
            ans = ans * 10 + dig;
            if (ans < pow(-2, 31) || ans > pow(2, 31) - 1)
            {
                return 0;
            }
            num /= 10;
        }
        return ans * sign;
    }
};