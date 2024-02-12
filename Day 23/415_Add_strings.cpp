// TC - O(n)
// SC - O(1)
class Solution
{
public:
    string addStrings(string num1, string num2)
    {
        string ans = "";
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry > 0)
        {
            int sum = 0;
            if (i >= 0)
            {
                sum += num1[i] - '0';
                i--;
            }
            if (j >= 0)
            {
                sum += num2[j] - '0';
                j--;
            }
            sum += carry;
            ans.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};