// TC - O(n)
// SC - O(n)
class Solution
{
public:
    int getLongestSubarray(vector<int> &A, int K)
    {
        int N = A.size();
        unordered_map<int, int> map;
        int presum = 0, res = 0;
        for (int i = 0; i < N; i++)
        {
            presum += A[i];
            if (presum == K)
            {
                res = i + 1;
            }
            if (map.find(presum) == map.end())
            {
                map.insert({presum, i});
            }
            if (map.find(presum - K) != map.end())
            {
                res = max(res, i - map[presum - K]);
            }
        }
        return res;
    }

    int findMaxLength(vector<int> &arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                arr[i] = -1;
            }
        }
        return getLongestSubarray(arr, 0);
    }
};