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
    int dia;
    int f(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int lh = f(root->left);
        int rh = f(root->right);

        dia = max(dia, lh + rh);
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        dia = 0;
        f(root);
        return dia;
    }
};