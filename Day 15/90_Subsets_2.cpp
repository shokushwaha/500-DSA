// TC - O(2^n)
// SC - O(n)
class Solution
{
private:
    void f(vector<vector<int>> &ans, vector<int> &temp, vector<int> arr, int ind)
    {
        if (ind >= arr.size())
        {
            ans.push_back(temp);
            return;
        }

        temp.push_back(arr[ind]);
        f(ans, temp, arr, ind + 1);
        temp.pop_back();

        while (ind < arr.size() - 1 && arr[ind] == arr[ind + 1])
            ind++;

        f(ans, temp, arr, ind + 1);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        f(ans, temp, arr, 0);
        return ans;
    }
};