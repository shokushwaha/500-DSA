/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// TC - O(n)
// SC - O(n)
class Solution
{
private:
    void makeParent(unordered_map<TreeNode *, TreeNode *> &parent, TreeNode *root)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left)
                {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right)
                {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        makeParent(parent, root);

        unordered_map<TreeNode *, bool> vis;
        queue<TreeNode *> q;
        q.push(target);
        vis[target] = true;

        vector<int> ans;

        while (!q.empty())
        {
            int n = q.size();
            if (k-- == 0)
            {
                break;
            }
            while (n--)
            {
                TreeNode *node = q.front();
                q.pop();

                if (node->left && !vis[node->left])
                {
                    vis[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !vis[node->right])
                {
                    vis[node->right] = true;
                    q.push(node->right);
                }
                if (parent[node] && !vis[parent[node]])
                {
                    vis[parent[node]] = true;
                    q.push(parent[node]);
                }
            }
        }

        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};