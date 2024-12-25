//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User Function Template
class Solution
{
    // Time Complexity: O(V^2)
    // Space Complexity: O(V)
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src)
    {
        int v = adj.size();
        vector<int> dist(v, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        dist[src] = 0;
        minHeap.push({0, src});
        while (!minHeap.empty())
        {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int currDist = curr.first;
            int currNode = curr.second;

            for (auto neighbor : adj[currNode])
            {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                if (currDist + edgeWeight < dist[nextNode])
                {
                    dist[nextNode] = currDist + edgeWeight;
                    minHeap.push({dist[nextNode], nextNode});
                }
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
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends