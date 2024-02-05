// TC - O(max(n,m))
// SC - O(1)
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> ans;
        int i = 0;
        int j = 0;
        while (i < firstList.size() && j < secondList.size())
        {
            int firstStart = firstList[i][0];
            int firstEnd = firstList[i][1];

            int secondStart = secondList[j][0];
            int secondEnd = secondList[j][1];

            if (secondEnd < firstStart)
            {
                j++;
            }
            else if (firstEnd < secondStart)
            {
                i++;
            }
            else
            {
                ans.push_back({max(firstStart, secondStart), min(firstEnd, secondEnd)});
                if (secondEnd < firstEnd)
                {
                    j++;
                }
                else
                {
                    i++;
                }
            }
        }
        return ans;
    }
};