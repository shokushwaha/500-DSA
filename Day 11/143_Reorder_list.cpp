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
    void reorderList(ListNode *head)
    {
        vector<ListNode *> v;
        ListNode *temp = head;
        while (temp != NULL)
        {
            v.push_back(temp);
            temp = temp->next;
        };
        int i = 0, j = v.size() - 1;
        head = v[i];
        head->next = v[j];
        i++;
        temp = head->next;
        while (j > i)
        {
            temp->next = v[i];
            temp = temp->next;
            j--;
            temp->next = v[j];
            temp = temp->next;
            i++;
        }
        temp->next = NULL;
    }
};