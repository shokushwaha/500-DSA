// TC - O(n)
// SC - O(n)
class Node
{
private:
    Node *links[26];
    bool flag;

public:
    void add(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd()
    {
        return flag;
    }
    bool contains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (auto it : word)
        {
            if (!node->contains(it))
            {
                node->add(it, new Node());
            }
            node = node->get(it);
        }
        node->setEnd();
    }

    bool search(string word)
    {
        Node *node = root;

        for (auto it : word)
        {
            if (node->contains(it))
            {
                node = node->get(it);
            }
            else
            {
                return false;
            }
        }
        return node->getEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;

        for (auto it : prefix)
        {
            if (node->contains(it))
            {
                node = node->get(it);
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */