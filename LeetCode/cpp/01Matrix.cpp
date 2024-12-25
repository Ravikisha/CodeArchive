class Solution
{
    // Time Complexity: O(V+E)
    // Space Complexity: O(V)
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        // Initialize the queue with all 0 cells and set their distance to 0
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }

        // Direction vectors for moving up, down, left, right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        // Perform BFS
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (auto dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;

                // Check bounds and if we can update the distance
                if (newX >= 0 && newX < m && newY >= 0 && newY < n)
                {
                    if (dist[newX][newY] > dist[x][y] + 1)
                    {
                        dist[newX][newY] = dist[x][y] + 1;
                        q.push({newX, newY});
                    }
                }
            }
        }

        return dist;
    }
};