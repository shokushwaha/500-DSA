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
    int f(TreeNode *root, int &maxi)
    {
        if (!root)
        {
            return 0;
        }
        int lh = max(0, f(root->left, maxi));
        int rh = max(0, f(root->right, maxi));

        maxi = max(maxi, root->val + lh + rh);
        return root->val + max(lh, rh);
    }

public:
    int maxPathSum(TreeNode *root)
    {

        int maxi = INT_MIN;
        f(root, maxi);
        return maxi;
    }
};