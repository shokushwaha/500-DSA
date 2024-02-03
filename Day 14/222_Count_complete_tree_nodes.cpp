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
    int leftHeight(TreeNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->left;
        }
        return cnt;
    }
    int rightHeight(TreeNode *root)
    {
        int cnt = 0;
        while (root)
        {
            cnt++;
            root = root->right;
        }
        return cnt;
    }
    int f(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }

        int lh = leftHeight(root);
        int rh = rightHeight(root);

        if (lh == rh)
        {
            return pow(2, lh) - 1;
        }
        else
        {
            return 1 + f(root->left) + f(root->right);
        }
    }

public:
    int countNodes(TreeNode *root)
    {
        return f(root);
    }
};