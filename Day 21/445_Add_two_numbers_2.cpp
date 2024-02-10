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
// TC - O(n)
// SC - O(1)
class Solution
{
private:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head, *nxt = NULL;
        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode *a = l1, *b = l2;

        int carry = 0;
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;

        while (a || b || carry)
        {
            int x = 0, y = 0;
            if (a)
            {
                x = a->val;
                a = a->next;
            }
            if (b)
            {
                y = b->val;
                b = b->next;
            }

            int sum = x + y + carry;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            carry = sum / 10;
        }
        dummy = dummy->next;
        dummy = reverse(dummy);
        return dummy;
    }
};