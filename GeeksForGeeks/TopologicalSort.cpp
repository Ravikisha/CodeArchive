//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        int v = adj.size();
        stack<int> s;
        vector<int> visited(v, 0);
        function<void(int)> dfs = [&](int node)
        {
            if (visited[node])
                return;
            visited[node] = 1;
            for (int i = 0; i < adj[node].size(); i++)
            {
                dfs(adj[node][i]);
            }
            s.push(node);
        };
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i);
            }
        }
        vector<int> result;
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        return result;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj)
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends

// Kahns Algorithm
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
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

        vector<int> result;
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            result.push_back(curr);
            for (auto it : adj[curr])
            {
                // Remove the indegree point from the curr node
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }
        return result;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj)
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> N >> E;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends