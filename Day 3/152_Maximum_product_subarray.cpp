// TC - O(n)
// SC - O(1)
class Solution
{
private:
    void f(vector<int> &nums, int &maxi)
    {
        int curr = 1;
        for (auto it : nums)
        {
            curr *= it;
            maxi = max(maxi, curr);
            if (curr == 0)
            {
                curr = 1;
            }
        }
    }

public:
    int maxProduct(vector<int> &nums)
    {
        int maxi = INT_MIN;
        f(nums, maxi);
        reverse(begin(nums), end(nums));
        f(nums, maxi);
        return maxi;
    }
};