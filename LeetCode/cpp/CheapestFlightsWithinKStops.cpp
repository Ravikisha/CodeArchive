class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        // build a adj list
        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<tuple<int, int, int>> q; // {stops, dest, cost}
        q.push(make_tuple(0, src, 0));
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while (!q.empty())
        {
            auto [stops, dest, cost] = q.front();
            q.pop();
            if (stops > k)
                continue;
            for (auto it : adj[dest])
            {
                int adjNode = it.first;
                int adjCost = it.second;

                if (cost + adjCost < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + adjCost;
                    q.push(make_tuple(stops + 1, adjNode, cost + adjCost));
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};