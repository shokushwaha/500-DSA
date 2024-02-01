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
    bool f(TreeNode *root, int targetSum, int curr)
    {
        if (!root)
        {
            return false;
        }
        curr += root->val;
        if (!root->left && !root->right)
        {
            return curr == targetSum;
        }
        return f(root->left, targetSum, curr) | f(root->right, targetSum, curr);
    }

public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int curr = 0;
        return f(root, targetSum, curr);
    }
};