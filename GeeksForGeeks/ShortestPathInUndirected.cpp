//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Back-end complete function Template for C++

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V+E)
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        int v = adj.size();
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            for (auto it : adj[curr])
            {
                if (dist[curr] + 1 < dist[it])
                {
                    dist[it] = dist[curr] + 1;
                    q.push(it);
                }
            }
        }
        for (int i = 0; i < v; i++)
        {
            if (dist[i] == INT_MAX)
            {
                dist[i] = -1;
            }
        }
        return dist;
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
        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int src;
        cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(adj, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
        cout << "~\n";
    }
}

// } Driver Code Ends