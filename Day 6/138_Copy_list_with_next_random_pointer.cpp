/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
// TC - O(n )
// SC - O(1)
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return head;
        }
        Node *temp = head;
        while (temp)
        {
            Node *nxt = temp->next;
            temp->next = new Node(temp->val);
            temp->next->next = nxt;
            temp = nxt;
        }

        temp = head;

        while (temp)
        {
            temp->next->random = temp->random ? temp->random->next : NULL;
            temp = temp->next->next;
        }

        Node *newNode = head->next;
        Node *odd = newNode;
        temp = head;
        while (temp && odd)
        {
            temp->next = temp->next->next;
            odd->next = odd->next ? odd->next->next : NULL;
            temp = temp->next;
            odd = odd->next;
        }

        return newNode;
    }
};