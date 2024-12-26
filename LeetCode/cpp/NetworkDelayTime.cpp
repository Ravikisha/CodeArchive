class Solution
{
    // Time Complexity: O(ElogV)
    // Space Complexity: O(V+E)
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // create adj list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // {cost, dest}
        minHeap.push({0, k});
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        while (!minHeap.empty())
        {
            pair<int, int> curr = minHeap.top();
            minHeap.pop();
            int cost = curr.first;
            for (auto it : adj[curr.second])
            {
                int adjNode = it.first;
                int adjCost = it.second;

                if (cost + adjCost < dist[adjNode])
                {
                    dist[adjNode] = cost + adjCost;
                    minHeap.push(make_pair(cost + adjCost, adjNode));
                }
            }
        }
        int maxDist = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1; // Unreachable node
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};