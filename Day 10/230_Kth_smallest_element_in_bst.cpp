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
    int kthSmallest(TreeNode *root, int k)
    {
        TreeNode *curr = root;
        int cnt = 0;
        int ans = 0;
        while (curr)
        {
            if (curr->left == NULL)
            {
                if (++cnt == k)
                {
                    ans = curr->val;
                }
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
                    if (++cnt == k)
                    {
                        ans = curr->val;
                    }
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};