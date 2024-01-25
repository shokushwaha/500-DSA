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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (!head || !head->next)
        {
            return NULL;
        }
        int len = findLen(head);
        if (len - n == 0)
        {
            return head->next;
        }
        ListNode *temp = head;
        ListNode *prev = NULL;
        int i = 0;
        while (i < len - n)
        {
            i++;
            prev = temp;
            temp = temp->next;
        }

        ListNode *nxt = temp->next;
        prev->next = nxt;
        return head;
    }
};