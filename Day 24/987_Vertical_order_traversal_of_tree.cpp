// TC - O(n)
// SC - O(n)
class Solution
{
public:
    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        map<int, map<int, vector<int>>> mp;
        queue<pair<TreeNode *, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            TreeNode *node = p.first;
            int x = p.second.first, y = p.second.second;
            mp[x][y].push_back(node->val);
            if (node->left)
            {
                q.push({node->left, {x - 1, y + 1}});
            }
            if (node->right)
            {
                q.push({node->right, {x + 1, y + 1}});
            }
        }
        vector<vector<int>> ans;
        for (auto &q : mp)
        {
            vector<int> col;
            for (auto &p : q.second)
            {
                sort(p.second.begin(), p.second.end());
                col.insert(col.end(), p.second.begin(), p.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};