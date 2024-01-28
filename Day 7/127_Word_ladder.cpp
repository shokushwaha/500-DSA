// TC - (nlogn)
// SC - (n)
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_set<string> st(begin(wordList), end(wordList));

        queue<pair<int, string>> q;
        q.push({1, beginWord});
        st.erase(beginWord);

        while (!q.empty())
        {
            int steps = q.front().first;
            string str = q.front().second;
            q.pop();
            if (str == endWord)
            {
                return steps;
            }

            for (int i = 0; i < str.size(); i++)
            {
                char original = str[i];
                for (char ch = 'a'; ch <= 'z'; ch++)
                {
                    str[i] = ch;
                    if (st.find(str) != st.end())
                    {
                        q.push({steps + 1, str});
                        st.erase(str);
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};