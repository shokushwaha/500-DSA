// TC - O(nlogn)
// SC - O(n)
class Solution
{
private:
    double f(double x, long n)
    {
        if (n == 0)
        {
            return 1;
        }

        if (n < 0)
        {
            return f(1 / x, -n);
        }

        if (n % 2 == 0)
        {
            return f(x * x, n / 2);
        }
        else
        {
            return x * f(x * x, (n - 1) / 2);
        }
    }

public:
    double myPow(double x, int n)
    {
        return f(x, (long)n);
    }
};