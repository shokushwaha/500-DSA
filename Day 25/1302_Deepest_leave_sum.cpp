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
public:
    int deepestLeavesSum(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode *> q;
        q.push(root);
        int sum = 0;
        while (!q.empty())
        {
            int n = q.size();
            int curr = 0;
            while (n--)
            {
                auto node = q.front();
                q.pop();

                curr += node->val;
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            sum = curr;
        }
        return sum;
    }
};