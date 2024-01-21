// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxi = INT_MIN;
        int curr = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right)
        {
            curr = min(height[left], height[right]) * (right - left);

            maxi = max(maxi, curr);

            if (height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return maxi;
    }
};