// TC - O(n)
// SC - O(1)
class Solution
{
public:
    int longestMountain(vector<int> &arr)
    {
        int ans = 0;

        int n = arr.size();
        for (int i = 1; i < n - 1; i++)
        {
            if (arr[i] > arr[i - 1] && arr[i + 1] < arr[i])
            {
                int left = i;
                int right = i;

                while (left > 0 && arr[left - 1] < arr[left])
                {
                    left--;
                }

                while (right < n - 1 && arr[right + 1] < arr[right])
                {
                    right++;
                }
                ans = max(ans, right - left + 1);
            }
        }
        return ans;
    }
};