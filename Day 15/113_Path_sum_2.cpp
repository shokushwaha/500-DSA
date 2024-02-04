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
// SC - O(n)
class Solution
{
private:
    void f(TreeNode *root, int tar, int curr, vector<vector<int>> &ans, vector<int> temp)
    {
        if (!root)
        {
            return;
        }
        curr += root->val;
        temp.push_back(root->val);
        if (!root->left && !root->right)
        {
            if (curr == tar)
            {
                ans.push_back(temp);
            }
            return;
        }
        f(root->left, tar, curr, ans, temp);
        f(root->right, tar, curr, ans, temp);
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;
        f(root, targetSum, sum, ans, temp);
        return ans;
    }
};