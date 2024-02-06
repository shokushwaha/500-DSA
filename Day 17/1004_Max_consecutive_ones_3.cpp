// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int len = 0;
        int left = -1;

        int right = 0;
        int cnt = 0;
        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                cnt++;
            }

            while (cnt > k && left <= right)
            {
                left++;
                if (nums[left] == 0)
                {
                    cnt--;
                }
            }
            len = max(len, right - left);

            right++;
        }
        return len;
    }
};
