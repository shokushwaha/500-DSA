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
// SC - O(1)
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        TreeNode *curr = root;
        vector<int> ans;

        while (curr)
        {
            if (curr->left == NULL)
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev && prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                else
                {
                    ans.push_back(curr->val);
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};