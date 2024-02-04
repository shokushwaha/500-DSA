// TC - O(n)
// SC - O(1)
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int first;
        int second;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == first)
            {
                cnt1++;
            }
            else if (nums[i] == second)
            {
                cnt2++;
            }
            else if (cnt1 == 0)
            {
                first = nums[i];
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                second = nums[i];
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        int x = 0;
        int y = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == first)
            {
                x++;
            }
            if (nums[i] == second)
            {
                y++;
            }
        }
        vector<int> ans;
        if (x > nums.size() / 3)
        {
            ans.push_back(first);
        }
        if (y > nums.size() / 3)
        {
            ans.push_back(second);
        }
        return ans;
    }
};