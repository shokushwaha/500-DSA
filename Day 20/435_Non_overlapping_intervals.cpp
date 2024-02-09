// TC - O(nlogn)
// SC - O(1)
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int cnt = 0;
        sort(begin(intervals), end(intervals));

        int i = 0;
        int j = 1;

        while (j < intervals.size())
        {
            int cs = intervals[i][0];
            int ce = intervals[i][1];
            int ns = intervals[j][0];
            int ne = intervals[j][1];

            if (ce <= ns)
            {
                i = j;
                j++;
            }
            else if (ce <= ne)
            {
                cnt++;
                j++;
            }
            else if (ce > ne)
            {
                i = j;
                j++;
                cnt++;
            }
        }
        return cnt;
    }
};