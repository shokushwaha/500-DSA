// TC - O(n)
// SC - O(n)
class Node
{
private:
    Node *links[2];
    bool flag;

public:
    void add(Node *node, int ch)
    {
        links[ch] = node;
    }
    bool containsKey(int ch)
    {
        return links[ch] != NULL;
    }
    Node *get(int ch)
    {
        return links[ch];
    }
    void setEnd()
    {
        flag = true;
    }
    bool getEnd()
    {
        return flag;
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

    void insert(int num)
    {
        Node *node = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (!node->containsKey(bit))
            {
                node->add(new Node(), bit);
            }
            node = node->get(bit);
        }
        node->setEnd();
    }

    int findMax(int num)
    {
        Node *node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                ans = ans | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return ans;
    }
};
class Solution
{
public:
    int findMaximumXOR(vector<int> &nums)
    {
        Trie trie;
        for (auto it : nums)
        {
            trie.insert(it);
        }
        int maxi = 0;
        for (auto it : nums)
        {
            maxi = max(maxi, trie.findMax(it));
        }
        return maxi;
    }
};