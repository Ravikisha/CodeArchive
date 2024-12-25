//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V+E)
public:
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        // topo sort
        stack<int> s;
        vector<int> visited(V, 0);
        function<void(int)> dfs = [&](int node)
        {
            visited[node] = 1;
            for (auto it : adj[node])
            {
                int v = it.first;
                if (!visited[v])
                {
                    dfs(v);
                }
            }
            s.push(node);
        };

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(i);
        }

        // find the distance
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;
        while (!s.empty())
        {
            int node = s.top();
            s.pop();
            if (dist[node] != INT_MAX)
            {
                for (auto it : adj[node])
                {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        for (int i = 0; i < V; i++)
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends