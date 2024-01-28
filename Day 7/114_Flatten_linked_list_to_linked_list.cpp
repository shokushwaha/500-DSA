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
    void flatten(TreeNode *root)
    {
        TreeNode *curr = root;
        while (curr)
        {
            if (curr->left == NULL)
            {
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev && prev->right && prev->right != curr)
                {
                    prev = prev->right;
                }
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
        }
    }
};