// TC - O(n)
// SC - O(n)
class DisjointSet
{
private:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findPar(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        return findPar(parent[x]);
    }

    void unionBySize(int u, int v)
    {
        int ulpU = findPar(u);
        int ulpV = findPar(v);

        if (ulpU == ulpV)
        {
            return;
        }

        if (size[ulpU] < size[ulpV])
        {
            parent[ulpU] = ulpV;
            size[ulpV] += size[ulpU];
        }
        else
        {
            parent[ulpV] = ulpU;
            size[ulpU] += size[ulpV];
        }
    }

    void unionByRank(int u, int v)
    {
        int ulpU = findPar(u);
        int ulpV = findPar(v);

        if (ulpU == ulpV)
        {
            return;
        }

        if (rank[ulpU] < rank[ulpV])
        {
            parent[ulpU] = ulpV;
        }
        else if (rank[ulpV] < rank[ulpU])
        {
            parent[ulpV] = ulpU;
        }
        else
        {
            parent[ulpU] = ulpV;
            rank[ulpV]++;
        }
    }
};
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();

        DisjointSet dS(n);
        vector<int> ans;
        for (auto it : edges)
        {
            if (dS.findPar(it[0]) == dS.findPar(it[1]))
            {
                ans.push_back(it[0]);
                ans.push_back(it[1]);
                return ans;
            }
            else
            {
                dS.unionBySize(it[0], it[1]);
            }
        }
        return ans;
    }
};