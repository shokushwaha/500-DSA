// TC - O(n*n)
// SC - O(n)
class Solution
{
public:
    struct TrieNode
    {
        TrieNode *child[26];
        bool flag = false;
        bool Inserted = false;
        string str;
        bool containChar(char character)
        {
            return (child[character - 'a'] != NULL);
        }
        void putNode(char nxtchar, TrieNode *node)
        {
            child[nxtchar - 'a'] = node;
        }
        TrieNode *getNode(char character)
        {
            return child[character - 'a'];
        }
        void setEnd()
        {
            flag = true;
        }
        bool isEnd()
        {
            return flag;
        }
        bool didInsert()
        {
            return Inserted;
        }
        void setdidInsert()
        {
            Inserted = true;
        }
    };
    TrieNode *root = new TrieNode();
    void insertWord(string word)
    {
        TrieNode *node = root;
        int i;
        for (i = 0; i < word.size(); i++)
        {
            if (node->containChar(word[i]) == false)
            {
                node->putNode(word[i], new TrieNode());
            }
            node = node->getNode(word[i]);
        }
        node->setEnd();
        node->str = word;
    }
    void dfs(vector<vector<char>> &board, int i, int j, TrieNode *node, vector<string> &ans, vector<vector<bool>> &visited)
    {
        if ((i < 0) || (j < 0) || (i > board.size() - 1) || (j > board[0].size() - 1))
        {
            return;
        }
        if (visited[i][j])
        {
            return;
        }
        node = node->getNode(board[i][j]);
        if (node == NULL)
        {
            return;
        }
        if (node->isEnd() && !(node->Inserted))
        {
            ans.push_back(node->str);
            node->Inserted = true;
        }
        visited[i][j] = true;
        dfs(board, i + 1, j, node, ans, visited);
        dfs(board, i, j + 1, node, ans, visited);
        dfs(board, i - 1, j, node, ans, visited);
        dfs(board, i, j - 1, node, ans, visited);
        visited[i][j] = false;
    }
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> ans;
        for (string word : words)
        {
            insertWord(word);
        }
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        int i, j;
        for (i = 0; i < board.size(); i++)
        {
            for (j = 0; j < board[0].size(); j++)
            {
                dfs(board, i, j, root, ans, visited);
            }
        }
        return ans;
    }
};