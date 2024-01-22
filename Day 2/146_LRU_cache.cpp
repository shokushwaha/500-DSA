// TC - O(1)
// SC - O(1)
class LRUCache
{
    class Node
    {
    public:
        int val;
        int key;
        Node *prev;
        Node *next;
        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);
    unordered_map<int, Node *> mp;
    int cap;

public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    void addNode(Node *node)
    {
        Node *temp = head->next;
        node->next = temp;
        head->next = node;
        node->prev = head;
        temp->prev = node;
    }
    void deleteNode(Node *node)
    {
        Node *delPrev = node->prev;
        Node *delNext = node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }
    int get(int key)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            int ans = node->val;
            mp.erase(key);
            deleteNode(node);
            addNode(node);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp.find(key) != mp.end())
        {
            Node *node = mp[key];
            mp.erase(key);
            deleteNode(node);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key, value));
        mp[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */