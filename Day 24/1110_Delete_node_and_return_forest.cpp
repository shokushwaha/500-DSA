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
    TreeNode *f(TreeNode *root, unordered_set<int> &st, vector<TreeNode *> &ans)
    {
        if (!root)
        {
            return NULL;
        }
        root->left = f(root->left, st, ans);
        root->right = f(root->right, st, ans);
        if (st.find(root->val) != st.end())
        {
            if (root->left)
            {
                ans.push_back(root->left);
            }
            if (root->right)
            {
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }

public:
    vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete)
    {
        vector<TreeNode *> ans;
        unordered_set<int> st(begin(to_delete), end(to_delete));
        f(root, st, ans);
        if (st.find(root->val) == st.end())
        {
            ans.push_back(root);
        }
        return ans;
    }
};