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
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        queue<pair<TreeNode *, long long int>> q;
        q.push({root, 0});

        long long int maxi = 0;

        while (!q.empty())
        {
            int n = q.size();
            long long int a = 0;
            long long int b = 0;
            long long int c = q.front().second;
            for (int i = 0; i < n; i++)
            {
                TreeNode *node = q.front().first;
                long long int w = q.front().second;
                q.pop();

                if (node->left)
                {
                    q.push({node->left, 2 * (w - c)});
                }
                if (node->right)
                {
                    q.push({node->right, 2 * (w - c) + 1});
                }
                if (i == 0)
                {
                    a = w;
                }
                if (i == n - 1)
                {
                    b = w;
                }
            }
            maxi = max(maxi, b - a + 1);
        }
        return maxi;
    }
};