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
// TC - O(nlogn)
// SC - O(h)
class Solution
{
    bool helper(TreeNode *root, int k, unordered_set<int> &st)
    {
        if (!root)
            return false;
        if (st.find(k - root->val) != st.end())
            return true;
        st.insert(root->val);
        return helper(root->left, k, st) || helper(root->right, k, st);
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> st;
        return helper(root, k, st);
    }
};