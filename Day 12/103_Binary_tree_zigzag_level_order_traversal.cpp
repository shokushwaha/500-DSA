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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
        {
            return {};
        }
        queue<TreeNode *> q;
        q.push(root);
        vector<vector<int>> ans;
        bool flag = false;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> temp;
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();

                temp.push_back(node->val);
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            if (flag)
            {
                reverse(begin(temp), end(temp));
            }
            ans.push_back(temp);
            flag = !flag;
        }
        return ans;
    }
};