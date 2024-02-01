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
public:
    bool isSameTree(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
        {
            return true;
        }
        if (!a || !b)
        {
            return false;
        }
        return a->val == b->val && isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
    }
};