/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// TC - O(n)
// SC - O(h)
class Solution
{
private:
    void f(TreeNode *root, int &ans, string str)
    {
        if (!root)
        {
            return;
        }
        str += to_string(root->val);
        if (!root->left && !root->right)
        {
            ans += stoi(str);
            return;
        }

        f(root->left, ans, str);
        f(root->right, ans, str);
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int ans = 0;

        string str = "";
        f(root, ans, str);
        return ans;
    }
};