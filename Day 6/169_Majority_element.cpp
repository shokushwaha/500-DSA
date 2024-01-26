// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ele = nums[0];
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == ele)
            {
                cnt++;
            }
            else
            {
                cnt--;
                if (cnt == 0)
                {
                    ele = nums[i];
                    cnt++;
                }
            }
        }
        cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == ele)
            {
                cnt++;
            }
        }
        if (cnt > nums.size() / 2)
        {
            return ele;
        }
        else
        {
            return -1;
        }
    }
};