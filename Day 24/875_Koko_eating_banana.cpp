// TC - O(nlogn)
// SC - O(1)
class Solution
{
public:
    long long int f(vector<int> &piles, int mid)
    {
        long long int sum = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            sum += ceil((double)piles[i] / (double)mid);
        }
        return sum;
    }
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int high = INT_MIN;
        for (int i = 0; i < piles.size(); i++)
        {
            high = max(high, piles[i]);
        }
        sort(piles.begin(), piles.end());
        int n = piles.size();
        int low = 1;

        int ans = -1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            long long int temp = f(piles, mid);
            if (temp <= h)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return ans;
    }
};