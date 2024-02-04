/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
// TC - O(nlogn)
// SC - O(n)
class Solution
{
private:
    TreeNode *f(ListNode *head)
    {
        if (!head)
        {
            return NULL;
        }
        if (!head->next)
        {
            return new TreeNode(head->val);
        }

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *slowPrev = head;
        while (fast && fast->next)
        {
            slowPrev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        slowPrev->next = NULL;
        TreeNode *root = new TreeNode(slow->val);
        root->left = f(head);
        root->right = f(slow->next);
        return root;
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        return f(head);
    }
};