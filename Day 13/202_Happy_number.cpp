// TC - O(n *n)
// SC - O(n)
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_map<int, int> mp;
        while (true)
        {

            int curr = 0;
            while (n)
            {
                int rem = n % 10;
                curr += rem * rem;
                n /= 10;
            }
            n = curr;
            if (curr == 1)
            {
                return true;
            }

            if (mp.find(curr) != mp.end())
            {
                return false;
            }
            mp[curr] = 1;
        }
        return false;
    }
};