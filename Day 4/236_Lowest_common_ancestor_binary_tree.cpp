/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TC - O(n)
// SC - O(h)
class Solution
{
private:
    TreeNode *fun(TreeNode *root, TreeNode *a, TreeNode *b)
    {
        if (!root)
        {
            return NULL;
        }

        if (root->val == a->val || root->val == b->val)
        {
            return root;
        }

        TreeNode *left = fun(root->left, a, b);
        TreeNode *right = fun(root->right, a, b);

        if (!left)
        {
            return right;
        }
        if (!right)
        {
            return left;
        }
        return root;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return fun(root, p, q);
    }
};