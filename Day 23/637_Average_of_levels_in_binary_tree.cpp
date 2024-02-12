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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        double sum = 0, avg = 0;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            avg = 0;
            sum = 0;
            int size = q.size(), s = q.size();
            while (size--)
            {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;

                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            avg = sum / s;
            ans.push_back(avg);
        }

        return ans;
    }
};