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
    bool f(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        if (!a || !b)
        {
            return false;
        }
        return a->val == b->val && f(a->left, b->right) && f(a->right, b->left);
    }

public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
        {
            return true;
        }
        return f(root->left, root->right);
    }
};