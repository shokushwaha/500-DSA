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
    int findMax(vector<int> &nums, int start, int end)
    {
        int ind = start;
        int maxi = INT_MIN;
        for (int i = start; i <= end; i++)
        {
            if (nums[i] > maxi)
            {
                maxi = nums[i];
                ind = i;
            }
        }
        return ind;
    }
    TreeNode *f(vector<int> &nums, int start, int end)
    {
        if (start > end)
        {
            return NULL;
        }

        int ind = findMax(nums, start, end);
        TreeNode *root = new TreeNode(nums[ind]);
        root->left = f(nums, start, ind - 1);
        root->right = f(nums, ind + 1, end);
        return root;
    }

public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return f(nums, 0, nums.size() - 1);
    }
};