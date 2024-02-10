// TC - O(n)
// SC - O(1)
class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *small_dummy = new ListNode(0);
        ListNode *greater_dummy = new ListNode(0);

        ListNode *small = small_dummy;
        ListNode *greater = greater_dummy;

        ListNode *current = head;

        while (current)
        {
            if (current->val < x)
            {
                small->next = current;
                small = small->next;
            }
            else
            {
                greater->next = current;
                greater = greater->next;
            }
            current = current->next;
        }

        greater->next = nullptr;
        small->next = greater_dummy->next;

        return small_dummy->next;
    }
};
