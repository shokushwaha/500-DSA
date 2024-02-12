// TC - O(nlogn+mlongm)
// SC - O(1)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int left = m - 1;
        int right = 0;

        while (left >= 0 && right < n)
        {
            if (nums1[left] > nums2[right])
            {
                swap(nums1[left], nums2[right]);
                left--;
                right++;
            }
            else
            {
                break;
            }
        }
        sort(begin(nums1), begin(nums1) + m);
        sort(begin(nums2), end(nums2));
        int j = 0;
        for (int i = m; i < m + n; i++)
        {
            nums1[i] = nums2[j++];
        }
    }
};