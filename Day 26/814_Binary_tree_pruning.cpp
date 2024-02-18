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
    TreeNode *f(TreeNode *root)
    {
        if (!root)
            return NULL;

        root->left = f(root->left);
        root->right = f(root->right);

        if (!root->left && !root->right && root->val == 0)
            return NULL;

        else
            return root;
    }

public:
    TreeNode *pruneTree(TreeNode *root)
    {
        return f(root);
    }
};