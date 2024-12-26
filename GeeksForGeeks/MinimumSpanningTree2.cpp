//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

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
    // Time complexity: O(ElogE)
    // Space complexity: O(V)
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<tuple<int, int, int>> edges;

        // Convert adjacency list to edge list
        for (int u = 0; u < V; u++)
        {
            for (auto &it : adj[u])
            {
                int v = it[0];
                int w = it[1];
                if (u < v)
                { // Avoid duplicate edges in undirected graph
                    edges.push_back(make_tuple(w, u, v));
                }
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        DSU dsu(V);
        int mstWeight = 0;

        for (auto &it : edges)
        {
            int w = get<0>(it);
            int u = get<1>(it);
            int v = get<2>(it);
            if (dsu.find(u) != dsu.find(v))
            {
                dsu.unionSet(u, v);
                mstWeight += w;
            }
        }

        return mstWeight;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends