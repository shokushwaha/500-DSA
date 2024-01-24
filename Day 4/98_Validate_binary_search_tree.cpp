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
    bool f(TreeNode *root, long mini, long maxi)
    {
        if (!root)
        {
            return true;
        }

        if (root->val > mini && root->val < maxi)
        {
            return true && f(root->left, mini, root->val) && f(root->right, root->val, maxi);
        }
        else
        {
            return false;
        }
    }

public:
    bool isValidBST(TreeNode *root)
    {
        return f(root, LONG_MIN, LONG_MAX);
    }
};