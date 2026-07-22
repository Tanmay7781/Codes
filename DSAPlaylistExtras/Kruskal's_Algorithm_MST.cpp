#include <vector>
#include <algorithm>
using namespace std;

class DisjointSet
{
    vector<int> parent, size;

public:
    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        DisjointSet ds(V);
        sort(edges.begin(), edges.end(), [](auto &a, auto &b)
             { return a[2] < b[2]; });

        int mstWeight = 0;

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWeight += wt;
                ds.unionBySize(u, v);
            }
        }

        return mstWeight;
    }
};
