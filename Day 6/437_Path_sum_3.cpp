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
// TC - O(2^n*h)
// SC - O(h)
class Solution
{
private:
    int cnt;
    void f(TreeNode *root, int tar, vector<int> temp)
    {
        if (!root)
        {
            return;
        }
        temp.push_back(root->val);
        f(root->left, tar, temp);
        f(root->right, tar, temp);

        long long sum = 0;
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            sum = sum + temp[i];
            if (sum == tar)
            {
                cnt++;
            }
        }
    }

public:
    int pathSum(TreeNode *root, int targetSum)
    {
        vector<int> temp;
        f(root, targetSum, temp);
        return cnt;
    }
};