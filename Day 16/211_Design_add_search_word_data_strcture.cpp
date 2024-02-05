// TC - O(n)
// SC - O(n)
class Node
{
private:
    Node *links[26];
    bool isLeaf;

public:
    bool containsKey(char ch)
    {
        return links[ch - 'a'];
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        isLeaf = true;
    }

    bool isEnd()
    {
        return isLeaf;
    }
};

class WordDictionary
{
public:
    Node *root;
    WordDictionary()
    {
        root = new Node();
    }

    void addWord(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool _search(string word, Node *node, int i)
    {
        if (i == word.length())
            return node->isEnd();
        bool ans = false;
        if (word[i] == '.')
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                if (node->containsKey(j))
                    ans = ans | _search(word, node->get(j), i + 1);
                if (ans)
                    return true;
            }
        }
        else
        {
            if (node->containsKey(word[i]))
                ans = _search(word, node->get(word[i]), i + 1);
        }
        return ans;
    }

    bool search(string word)
    {
        return _search(word, root, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */