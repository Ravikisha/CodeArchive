class Solution
{
    // Time Complexity: O((V+E)logV)
    // Space Complexity: O(V+E)
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int mod = 1e9 + 7;
        // build the adj list
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            minHeap; // {distance, node}
        dist[0] = 0;
        ways[0] = 1;
        minHeap.push({0, 0});
        while (!minHeap.empty())
        {
            auto [currDist, node] = minHeap.top();
            minHeap.pop();
            // Skip outdated entries
            if (currDist > dist[node])
                continue;

            for (auto &[adjNode, adjCost] : adj[node])
            {
                long long newDist = currDist + adjCost;

                // Found a shorter path
                if (newDist < dist[adjNode])
                {
                    dist[adjNode] = newDist;
                    ways[adjNode] = ways[node];
                    minHeap.emplace(newDist, adjNode);
                }
                // Found an equal shortest path
                else if (newDist == dist[adjNode])
                {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return dist[n - 1] == LLONG_MAX ? 0 : ways[n - 1];
    }
};