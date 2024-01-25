// TC - O(n)
// SC - O(n)
class Solution
{
private:
    vector<int> prevSmaller(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nextSmaller(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans.push_back(n);
            }
            else
            {
                ans.push_back(st.top());
            }
            st.push(i);
        }
        reverse(begin(ans), end(ans));
        return ans;
    }

public:
    int largestRectangleArea(vector<int> &heights)
    {
        vector<int> prev = prevSmaller(heights);
        vector<int> next = nextSmaller(heights);
        int maxi = INT_MIN;
        int n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int width = next[i] - prev[i] - 1;
            int height = heights[i];
            maxi = max(maxi, width * height);
        }
        return maxi;
    }
};