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
// TC - O(nlogn)
// SC - O(n)
class Solution
{
private:
    ListNode *merge(ListNode *a, ListNode *b)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;
        ListNode *x = a;
        ListNode *y = b;

        while (x && y)
        {
            if (x->val < y->val)
            {
                ans->next = new ListNode(x->val);
                x = x->next;
            }
            else
            {
                ans->next = new ListNode(y->val);
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
        dummy = dummy->next;
        return dummy;
    }
    ListNode *findMid(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (slow && fast && fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *mid = findMid(head);
        ListNode *first = head;
        ListNode *second = mid->next;
        mid->next = NULL;

        ListNode *left = sortList(first);
        ListNode *right = sortList(second);

        return merge(left, right);
    }
};