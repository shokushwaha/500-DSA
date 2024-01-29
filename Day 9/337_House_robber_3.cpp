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
public:
    pair<int, int> solve(TreeNode *root)
    {
        if (root == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }
        pair<int, int> left = solve(root->left);
        pair<int, int> right = solve(root->right);
        pair<int, int> result;
        result.first = root->val + left.second + right.second;
        result.second = max(left.first, left.second) + max(right.first, right.second);
        return {result.first, result.second};
    }
    int rob(TreeNode *root)
    {
        pair<int, int> n = solve(root);
        return max(n.first, n.second);
    }
};