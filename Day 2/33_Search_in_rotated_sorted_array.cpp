// TC - O(logn)
// SC - O(1)
class Solution
{
public:
    int getPivot(vector<int> nums)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int mid = l + (r - l) / 2;

        while (l < r)
        {
            if (nums[mid] >= nums[0])
                l = mid + 1;

            else
                r = mid;

            mid = l + (r - l) / 2;
        }
        return l;
    }

    int binary(vector<int> nums, int l, int r, int target)
    {
        while (l <= r)
        {
            int mid = (r + l) / 2;

            if (nums[mid] == target)
                return mid;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }

    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int pivot = getPivot(nums);

        if (nums[pivot] <= target && target <= nums[n - 1])
            return binary(nums, pivot, n - 1, target);

        else
            return binary(nums, 0, pivot - 1, target);
    }
};