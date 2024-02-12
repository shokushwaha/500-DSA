// TC - O(n*m)
// SC - O(n)
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> mp;

        for (auto a : nums3)
        {
            for (auto b : nums4)
            {
                mp[a + b]++;
            }
        }

        int cnt = 0;
        for (auto a : nums1)
        {
            for (auto b : nums2)
            {
                if (mp.find(-(a + b)) != mp.end())
                {
                    cnt += mp[-(a + b)];
                }
            }
        }
        return cnt;
    }
};