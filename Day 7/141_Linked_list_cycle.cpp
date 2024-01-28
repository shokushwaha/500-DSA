/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// TC - O(n)
// SC - (1)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
        {
            return false;
        }
        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};