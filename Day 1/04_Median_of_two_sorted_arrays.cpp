// TC - O(min(n,m))
// SC - O(1)
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &array1, vector<int> &array2)
    {
        int size1 = array1.size();
        int size2 = array2.size();
        if (size1 > size2)
            return findMedianSortedArrays(array2, array1);
        int low = 0;
        int high = size1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int cut1 = mid;
            int cut2 = (size1 + size2) / 2 - cut1;
            int left1_last = (cut1 > 0) ? array1[cut1 - 1] : INT_MIN;
            int left2_last = (cut2 > 0) ? array2[cut2 - 1] : INT_MIN;
            int right1_first = (cut1 < size1) ? array1[cut1] : INT_MAX;
            int right2_first = (cut2 < size2) ? array2[cut2] : INT_MAX;
            if (left1_last <= right2_first && left2_last <= right1_first)
            {
                if ((size1 + size2) % 2 == 0)
                {
                    int first = max(left1_last, left2_last);
                    int second = min(right1_first, right2_first);
                    return ((double)first + (double)second) / 2;
                }
                else
                {
                    return (double)min(right1_first, right2_first);
                }
            }
            else if (left1_last > right2_first)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return 0;
    }
};