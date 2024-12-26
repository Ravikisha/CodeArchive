class Solution
{
    // Time Complexity: O(n^3)
    // Space Complexity: O(n^2)
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // Initialize distances with given edges
        for (auto it : edges)
        {
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];
        }

        // Distance to self is zero
        for (int i = 0; i < n; i++)
            dist[i][i] = 0;

        // Floyd-Warshall algorithm to find all-pairs shortest path
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                        continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        // Find the city with the smallest number of reachable cities
        int countCity = INT_MAX;
        int cityNo = -1;
        for (int city = 0; city < n; city++)
        {
            int count = 0;
            for (int adjCity = 0; adjCity < n; adjCity++)
            {
                if (dist[city][adjCity] <= distanceThreshold)
                {
                    count++;
                }
            }
            // Prefer the smaller city index in case of ties
            if (count < countCity || (count == countCity && city > cityNo))
            {
                countCity = count;
                cityNo = city;
            }
        }

        return cityNo;
    }
};