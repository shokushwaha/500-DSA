// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;

        for (auto it : asteroids)
        {
            while (!st.empty() && st.top() > 0 && it < 0)
            {
                int sum = st.top() + it;

                if (sum > 0)
                {
                    it = 0;
                }
                else if (sum < 0)
                {
                    st.pop();
                }
                else
                {
                    st.pop();
                    it = 0;
                }
            }
            if (it != 0)
            {
                st.push(it);
            }
        }

        int n = st.size();
        vector<int> ans(n);

        while (!st.empty())
        {
            ans[--n] = st.top();
            st.pop();
        }
        return ans;
    }
};