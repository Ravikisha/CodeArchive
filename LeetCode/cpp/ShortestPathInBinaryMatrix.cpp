class Solution
{
    // Time Complexity: O(V^2)
    // Space Complexity: O(V)
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push(make_tuple(1, 0, 0));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
        while (!minHeap.empty())
        {
            auto [wt, r, c] = minHeap.top();
            minHeap.pop();
            if (r == n - 1 && c == n - 1)
                return wt;
            for (int i = 0; i < dirs.size(); i++)
            {
                int newr = r + dirs[i].first;
                int newc = c + dirs[i].second;

                if (newr >= 0 && newr < n && newc >= 0 && newc < n && grid[newr][newc] == 0 && wt + 1 < dist[newr][newc])
                {
                    dist[newr][newc] = wt + 1;
                    minHeap.push(make_tuple(wt + 1, newr, newc));
                }
            }
        }
        return -1;
    }
};