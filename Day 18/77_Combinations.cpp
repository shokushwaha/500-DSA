// TC - O(2^n)
// SC - O(n)
class Solution
{
private:
    void f(vector<vector<int>> &ans, vector<int> &temp, vector<int> &arr, int ind, int n, int k)
    {
        if (ind == n)
        {
            if (temp.size() == k)
            {
                ans.push_back(temp);
            }
            return;
        }

        f(ans, temp, arr, ind + 1, n, k);

        temp.push_back(arr[ind]);
        f(ans, temp, arr, ind + 1, n, k);
        temp.pop_back();
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> arr;
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
        vector<vector<int>> ans;
        vector<int> temp;

        f(ans, temp, arr, 0, n, k);
        return ans;
    }
};