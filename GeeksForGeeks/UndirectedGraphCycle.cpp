//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &visited)
    {
        visited[node] = 1;
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                if (dfs(it, node, adj, visited))
                    return true;
            }
            else if (it != parent)
            {
                // A back edge detected
                return true;
            }
        }
        return false;
    }

    // Function to detect cycle in an undirected graph
    bool isCycle(vector<vector<int>> &adj)
    {
        int v = adj.size();
        vector<int> visited(v, 0); // Using `int` for visited

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
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
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends