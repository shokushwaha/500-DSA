// TC - O(logn)
// SC - O(1)
class Solution
{
public:
    bool search(vector<int> &arr, int target)
    {

        int start = 0;
        int n = arr.size();
        int end = n - 1;

        while (start <= end)
        {
            int mid = (end + start) / 2;

            if (arr[mid] == target)
            {
                return true;
            }

            else if (arr[start] == arr[mid] && arr[mid] == arr[end])
            {
                start++;
                end--;
            }

            else if (arr[start] <= arr[mid])
            {
                if (arr[start] <= target && target <= arr[mid])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }

            else if (arr[end] >= arr[mid])
            {
                if (arr[mid] <= target && target <= arr[end])
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};