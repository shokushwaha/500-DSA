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
// SC - O(n)
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || !head->next)
            return head;

        stack<ListNode *> st;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        for (int i = 1; i <= left - 1; i++)
        {
            prev = prev->next;
        }

        ListNode *curr = prev->next;
        for (int i = left; i <= right; i++)
        {
            st.push(curr);
            curr = curr->next;
        }

        ListNode *storeRightNext = st.top()->next;

        while (!st.empty())
        {
            prev->next = st.top();
            st.pop();
            prev = prev->next;
        }

        prev->next = storeRightNext;
        return dummy->next;
    }
};