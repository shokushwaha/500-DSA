// TC - O(logn)
// SC - O(1)
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ind = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                ind = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ind + 1;
    }
};