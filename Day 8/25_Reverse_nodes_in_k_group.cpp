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
// TC- O(n)
// SC - O(n)
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int len = getLen(head);

        int i = 0;
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nxt = NULL;
        while (curr && i < k)
        {
            i++;
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        len -= k;

        if (len >= k)
        {
            head->next = reverseKGroup(nxt, k);
        }
        else
        {
            head->next = nxt;
        }
        return prev;
    }
};