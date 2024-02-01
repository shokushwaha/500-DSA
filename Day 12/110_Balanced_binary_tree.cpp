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
    pair<int, bool> f(TreeNode *root)
    {
        if (!root)
        {
            return {0, true};
        }
        auto lh = f(root->left);
        auto rh = f(root->right);

        if (lh.second && rh.second && abs(lh.first - rh.first) <= 1)
        {
            return {1 + max(lh.first, rh.first), true};
        }
        else
        {
            return {0, false};
        }
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return f(root).second;
    }
};