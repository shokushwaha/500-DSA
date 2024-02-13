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
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        queue<TreeNode *> q;
        q.push(root);
        string ans = "";

        while (!q.empty())
        {
            int n = q.size();

            while (n--)
            {
                auto node = q.front();
                q.pop();
                if (node == NULL)
                {
                    ans += "#,";
                }
                else
                {
                    ans += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.size() == 0)
        {
            return NULL;
        }
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(ss, str, ',');
            if (str == "#")
            {
                node->left = NULL;
            }
            else
            {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            getline(ss, str, ',');
            if (str == "#")
            {
                node->right = NULL;
            }
            else
            {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;