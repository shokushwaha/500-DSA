// TC -O(nlogn)
// SC - O(n)
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        set<int> st(begin(nums), end(nums));

        nums.clear();
        for (auto it : st)
        {
            nums.push_back(it);
        }
        int left = -1;
        int right = 0;
        int maxi = 0;

        while (right < nums.size())
        {
            while (right + 1 < nums.size() && nums[right] + 1 == nums[right + 1])
            {
                right++;
            }
            maxi = max(maxi, right - left);
            left = right;
            right++;
        }
        return maxi;
    }
};