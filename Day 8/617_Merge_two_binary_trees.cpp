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
// TC - O(n*n)
// SC - O(h)
class Solution
{
private:
    TreeNode *f(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return NULL;
        }
        if (!a)
        {
            return b;
        }
        if (!b)
        {
            return a;
        }

        int val = 0;
        if (a)
        {
            val += a->val;
        }
        if (b)
        {
            val += b->val;
        }
        TreeNode *root = new TreeNode(val);
        root->left = f(a->left, b->left);
        root->right = f(a->right, b->right);

        return root;
    }

public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        return f(root1, root2);
    }
};