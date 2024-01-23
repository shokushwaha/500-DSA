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
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;

        ListNode *x = list1;
        ListNode *y = list2;

        while (x && y)
        {
            if (x->val < y->val)
            {
                ans->next = x;
                x = x->next;
            }
            else
            {
                ans->next = y;
                y = y->next;
            }
            ans = ans->next;
        }
        if (x)
        {
            ans->next = x;
        }
        if (y)
        {
            ans->next = y;
        }
        return dummy->next;
    }
};