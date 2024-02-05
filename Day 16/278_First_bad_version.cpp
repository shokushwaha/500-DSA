// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// TC - O(logn)
// SC - O(1)
class Solution
{
public:
    int firstBadVersion(int n)
    {
        int s = 1, e = n, mid;
        while (s < e)
        {
            mid = s + (e - s) / 2;
            if (isBadVersion(mid))
                e = mid;
            else
                s = mid + 1;
        }
        return e;
    }
};