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
// TC - O(n+m)
// SC - O(1)
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;
        ListNode *a = l1;
        ListNode *b = l2;
        int carry = 0;
        while (a || b || carry)
        {
            int x = 0;
            int y = 0;
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
            int digit = sum % 10;
            carry = sum / 10;
            ans->next = new ListNode(digit);
            ans = ans->next;
        }
        return dummy->next;
    }
};