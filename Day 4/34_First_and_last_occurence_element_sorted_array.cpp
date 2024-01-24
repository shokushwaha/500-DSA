// TC - O(logn)
// SC - O(1)
class Solution
{
private:
    int left(vector<int> &nums, int tar)
    {
        int ind = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tar)
            {
                ind = mid;
                end = mid - 1;
            }
            else if (nums[mid] < tar)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ind;
    }
    int right(vector<int> &nums, int tar)
    {
        int ind = -1;
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tar)
            {
                ind = mid;
                start = mid + 1;
            }
            else if (nums[mid] < tar)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return ind;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2);
        ans[0] = left(nums, target);
        ans[1] = right(nums, target);
        return ans;
    }
};