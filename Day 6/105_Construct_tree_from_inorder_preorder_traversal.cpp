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
// TC -O(n)
// SC -O(n)
class Solution
{
private:
    TreeNode *f(int preStart, int preEnd, int &ind, unordered_map<int, int> &mp, vector<int> &preorder)
    {
        if (preStart > preEnd || ind >= preorder.size())
        {
            return NULL;
        }
        int ele = preorder[ind++];
        int pos = mp[ele];

        TreeNode *root = new TreeNode(ele);
        root->left = f(preStart, pos - 1, ind, mp, preorder);
        root->right = f(pos + 1, preEnd, ind, mp, preorder);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = inorder.size();

        int preStart = 0;
        int preEnd = n - 1;

        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        int ind = 0;
        return f(preStart, preEnd, ind, mp, preorder);
    }
};