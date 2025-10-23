class DSU
{
public:
    DSU(int n) : parent(n + 1, -1) {}

    vector<int> parent;

    int find(int x)
    {
        if (parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);

        if (a == b) return false;
        if (parent[a] > parent[b]) swap(a, b);
        if (parent[a] == parent[b]) --parent[a];

        parent[b] = a;

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());

        for (vector<int> &edge : edges)
        {
            if (!dsu.unite(edge[0], edge[1]))
            {
                return vector<int>{edge[0], edge[1]};
            }
        }

        return vector<int>();
    }
};