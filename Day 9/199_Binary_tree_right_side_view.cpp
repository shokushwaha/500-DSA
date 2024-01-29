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
// TC - O(2^n)
// SC - O(h)
class Solution
{
private:
    void f(TreeNode *root, vector<int> &ans, int level)
    {
        if (!root)
        {
            return;
        }
        if (ans.size() == level)
        {
            ans.push_back(root->val);
        }
        f(root->right, ans, level + 1);
        f(root->left, ans, level + 1);
    }

public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        f(root, ans, 0);
        return ans;
    }
};