// TC - O(nlogn)
// SC - O(n)
class Node
{
private:
    Node *links[26];
    bool flag;
    int cntEnd;
    int cntPrefix;

public:
    void putKey(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    bool findKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    Node *getKey(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }

    void increaseEnd()
    {
        cntEnd++;
    }
    void increasePrefix()
    {
        cntPrefix++;
    }
    int findCntEnd()
    {
        return cntEnd;
    }
    int findCntPrefix()
    {
        return cntPrefix;
    }
    bool isEnd()
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

    void insert(string str)
    {
        Node *curr = root;
        for (auto it : str)
        {
            if (!curr->findKey(it))
            {
                curr->putKey(it, new Node());
            }
            curr = curr->getKey(it);
            curr->increasePrefix();
        }

        curr->setEnd();
        curr->increaseEnd();
    }
    string findMax(int n, string str)
    {
        Node *curr = root;
        string ans = "";
        for (auto it : str)
        {
            if (curr->findKey(it))
            {
                curr = curr->getKey(it);

                if (curr->findCntPrefix() == n)
                    ans += it;
                else
                    break;
            }
            else
                break;
        }
        return ans;
    }
};
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        Trie trie;
        for (auto it : strs)
        {
            trie.insert(it);
        }
        sort(strs.begin(), strs.end());
        string ans = trie.findMax(strs.size(), strs[0]);
        return ans;
    }
};