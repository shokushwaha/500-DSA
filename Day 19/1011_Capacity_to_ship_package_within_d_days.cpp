// TC - O(nlogn)
// SC - O(1)
class Solution
{
public:
    int getNumberOfDays(vector<int> &arr, int max_w, int days)
    {
        int ld_pr_dy = 0, cd = 1;
        for (int i = 0; i < arr.size(); i++)
        {
            if (ld_pr_dy + arr[i] > max_w)
            {
                cd += 1;
                ld_pr_dy = arr[i];
            }
            else
            {
                ld_pr_dy += arr[i];
            }
        }
        return cd;
    }
    int shipWithinDays(vector<int> &arr, int days)
    {
        long int total = 0;
        int big = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            total += arr[i];
            big = max(big, arr[i]);
        }
        long int low = big, high = total;
        while (low <= high)
        {
            long int mid = low + (high - low) / 2;
            int num_of_days = getNumberOfDays(arr, mid, days);
            if (num_of_days <= days)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};