// TC- O(1)
// SC - O(n)
class RandomizedSet
{
private:
    unordered_set<int> st;

public:
    RandomizedSet()
    {
        st.clear();
    }

    bool insert(int val)
    {
        if (st.find(val) == st.end())
        {
            st.insert(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    bool remove(int val)
    {
        if (st.find(val) != st.end())
        {
            st.erase(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    int getRandom()
    {
        return *next(begin(st), rand() % st.size());
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */