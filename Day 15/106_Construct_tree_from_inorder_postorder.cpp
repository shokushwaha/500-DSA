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
// TC - O(n*n)
// SC - O(n)
class Solution
{
private:
    TreeNode *f(vector<int> &postOrder, int postStart, int postEnd, unordered_map<int, int> &mp, int &ind)
    {
        if (postStart > postEnd || ind < 0)
        {
            return NULL;
        }
        int ele = postOrder[ind--];
        int pos = mp[ele];

        TreeNode *root = new TreeNode(ele);
        root->right = f(postOrder, pos + 1, postEnd, mp, ind);
        root->left = f(postOrder, postStart, pos - 1, mp, ind);
        return root;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        int postStart = 0;
        int postEnd = n - 1;
        int ind = n - 1;
        return f(postorder, postStart, postEnd, mp, ind);
    }
};