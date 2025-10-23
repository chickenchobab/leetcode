class DSU
{
public:
    DSU(int n) : parent(n + 1, -1), numSet(n) {}

    int numSet;
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
        
        --numSet;
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        vector<pair<int, int>> edgesPerType[3];

        for (vector<int>& edge : edges)
        {
            edgesPerType[edge[0] - 1].push_back({edge[1], edge[2]});
        }

        vector<DSU> dsu(3, DSU(n));
        int numConnection = 0;

        for (auto [a, b] : edgesPerType[2])
        {
            numConnection += dsu[2].unite(a, b);
        }

        for (int t = 0; t < 2; ++t) 
        {
            for (auto [a, b] : edgesPerType[2])
            {
                if (dsu[t].unite(a, b) && dsu[2].find(a) != dsu[2].find(b))
                {
                    ++numConnection;
                }
            }

            for (auto [a, b] : edgesPerType[t])
            {
                if (dsu[t].unite(a, b) && dsu[2].find(a) != dsu[2].find(b))
                {
                    ++numConnection;
                }
            }

        }

        // for (int t = 0; t < 3; ++t)
        // {
        //     cout << t << ": ";
        //     for (int i = 1; i <= n; ++i)
        //     {
        //         cout << dsu[t].parent[i] << ' ';
        //     }
        //     cout << endl;
        // }

        if (dsu[0].numSet == 1 && dsu[1].numSet == 1)
        {
            return edges.size() - numConnection;
        }
        return -1;
    }
};