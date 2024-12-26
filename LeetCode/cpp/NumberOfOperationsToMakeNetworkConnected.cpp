class DSU
{
public:
    vector<int> parent, rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // Initialize each node as its own parent
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSet(int x, int y)
    {
        int parentX = find(x);
        int parentY = find(y);

        if (parentX != parentY)
        {
            if (rank[parentX] > rank[parentY])
            {
                parent[parentY] = parentX;
            }
            else if (rank[parentX] < rank[parentY])
            {
                parent[parentX] = parentY;
            }
            else
            {
                parent[parentY] = parentX;
                rank[parentX]++;
            }
        }
    }
};

class Solution
{
    // Time Complexity: O(ElogE)
    // Space Complexity: O(V)
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        DSU ds(n);
        int countExtra = 0;
        for (auto it : connections)
        {
            int u = it[0];
            int v = it[1];
            if (ds.find(u) == ds.find(v))
            {
                countExtra++;
            }
            else
            {
                ds.unionSet(u, v);
            }
        }
        int countC = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                countC++;
        }
        int ans = countC - 1;
        if (countExtra >= ans)
            return ans;
        return -1;
    }
};