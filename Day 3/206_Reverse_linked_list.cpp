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
    typedef ListNode *L;

public:
    ListNode *reverseList(ListNode *head)
    {
        L curr = head;
        L prev = NULL;
        L nxt = NULL;

        while (curr)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
};