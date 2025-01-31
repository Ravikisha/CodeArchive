//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);

        // DFS Implement
        function<bool(int)> dfs = [&](int node)
        {
            vis[node] = 1;
            pathVis[node] = 1;
            for (auto it : adj[node])
            {

                if (!vis[it])
                {
                    if (dfs(it))
                        return true;
                }
                // if the node has been visited on the same path previously
                else if (pathVis[it])
                {
                    return true;
                }
            }
            pathVis[node] = 0;
            return false;
        };

        for (int i = 0; i < v; i++)
        {
            if (!vis[i])
            {
                if (dfs(i))
                    return true;
            }
        }
        return false;
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
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends

// Kahns Algorithm (BFS)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj)
    {
        int v = adj.size();
        vector<int> inDegree(v, 0);
        // InDegree Table
        for (int i = 0; i < v; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }
        int count = 0;

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            count++;
            for (auto it : adj[curr])
            {
                // Remove the indegree point from the curr node
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        if (count == v)
            return false;
        return true;
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
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends