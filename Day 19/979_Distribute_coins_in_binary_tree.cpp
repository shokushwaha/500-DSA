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
    int moves;
    int f(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int lh = f(root->left);
        int rh = f(root->right);

        moves += abs(lh) + abs(rh);

        return lh + rh + root->val - 1;
    }

public:
    int distributeCoins(TreeNode *root)
    {
        moves = 0;
        f(root);
        return moves;
    }
};