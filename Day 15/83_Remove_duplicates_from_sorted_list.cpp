// TC - O(n)
// SC - O(1)
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;

        while (temp->next != NULL)
        {
            if (temp->val == temp->next->val)
            {

                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return head;
    }
};