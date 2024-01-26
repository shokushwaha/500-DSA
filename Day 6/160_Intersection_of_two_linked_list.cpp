/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// TC - O(n)
// SC -O(1)
class Solution
{
private:
    int findLen(ListNode *head)
    {
        ListNode *temp = head;
        int cnt = 0;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int a = findLen(headA);
        int b = findLen(headB);

        ListNode *x = headA;
        ListNode *y = headB;
        int dif = abs(a - b);
        if (a > b)
        {
            while (dif--)
            {
                x = x->next;
            }
        }
        if (a < b)
        {
            while (dif--)
            {
                y = y->next;
            }
        }

        while (x != y)
        {
            x = x->next;
            y = y->next;
        }
        return x;
    }
};