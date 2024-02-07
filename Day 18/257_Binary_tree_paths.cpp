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
    void f(TreeNode *root, vector<string> &ans, string temp)
    {
        if (!root)
        {
            return;
        }
        temp += to_string(root->val) + "->";
        if (!root->left && !root->right)
        {
            temp.pop_back();
            temp.pop_back();
            ans.push_back(temp);
            return;
        }
        f(root->left, ans, temp);
        f(root->right, ans, temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> ans;
        string temp = "";

        f(root, ans, temp);
        return ans;
    }
};