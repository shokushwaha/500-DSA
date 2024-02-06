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
    int getLen(ListNode *head)
    {
        int cnt = 0;
        while (head)
        {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }
        int len = getLen(head);
        k = k % len;

        if (len == k || k == 0)
        {
            return head;
        }
        ListNode *temp = head;
        int i = 0;
        while (i < len - k - 1)
        {
            i++;
            temp = temp->next;
        }

        ListNode *old = temp;
        ListNode *newHead = temp->next;
        temp = newHead;
        while (temp && temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;
        old->next = NULL;
        return newHead;
    }
};