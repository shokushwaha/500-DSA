// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[numbers[i]] = i;
        }

        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++)
        {
            if (mp.find(target - numbers[i]) != mp.end())
            {
                ans.push_back(i + 1);
                ans.push_back(mp[target - numbers[i]] + 1);
                break;
            }
        }
        return ans;
    }
};