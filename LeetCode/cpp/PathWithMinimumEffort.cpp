class Solution
{
    // Time Complexity: O(V^2)
    // Space Complexity: O(V)
public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> minHeap;
        minHeap.push(make_tuple(0, 0, 0));
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!minHeap.empty())
        {
            auto [diff, r, c] = minHeap.top();
            minHeap.pop();
            if (r == m - 1 && c == n - 1)
                return diff;
            for (int i = 0; i < dirs.size(); i++)
            {
                int newr = r + dirs[i].first;
                int newc = c + dirs[i].second;

                if (newr >= 0 && newr < m && newc >= 0 && newc < n)
                {
                    int newEffort = max(abs(heights[r][c] - heights[newr][newc]), diff);
                    if (newEffort < dist[newr][newc])
                    {
                        dist[newr][newc] = newEffort;
                        minHeap.push(make_tuple(dist[newr][newc], newr, newc));
                    }
                }
            }
        }
        return 0;
    }
};