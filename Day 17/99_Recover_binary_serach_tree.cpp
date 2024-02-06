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
    TreeNode *first;
    TreeNode *mid;
    TreeNode *last;
    TreeNode *prev;
    void f(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        f(root->left);

        if (prev && prev->val > root->val)
        {
            if (first == NULL)
            {
                first = prev;
                mid = root;
            }
            else
            {
                last = root;
            }
        }
        prev = root;

        f(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = NULL;
        mid = NULL;
        last = NULL;
        prev = NULL;
        f(root);

        if (first && last)
        {
            swap(first->val, last->val);
        }
        else
        {
            swap(first->val, mid->val);
        }
    }
};