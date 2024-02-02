// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> l(n), r(n);
        int mn = 1e9, mx = -1e9;

        for (int i = 0; i < n; i++)
        {
            mx = max(mx, nums[i]);
            l[i] = mx;

            mn = min(mn, nums[n - i - 1]);
            r[n - i - 1] = mn;
        }

        int s = -1, e = -1;
        for (int i = 0; i < n; i++)
        {
            if (l[i] > r[i] && s == -1)
                s = i;
            if (l[n - i - 1] > r[n - i - 1] && e == -1)
                e = n - i - 1;
        }
        return s == -1 ? 0 : e - s + 1;
    }
};
