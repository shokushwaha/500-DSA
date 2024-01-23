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
// TC - O(nlogk)
// SC - O(n)
class Solution
{
private:
    typedef ListNode *L;
    class comp
    {
    public:
        bool operator()(L a, L b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<L, vector<L>, comp> pq;

        for (auto it : lists)
        {
            if (it)
            {
                pq.push(it);
            }
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *ans = dummy;

        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();

            ans->next = new ListNode(node->val);
            ans = ans->next;
            if (node->next)
            {
                pq.push(node->next);
            }
        }
        dummy = dummy->next;
        return dummy;
    }
};