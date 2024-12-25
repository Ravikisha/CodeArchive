class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        function<void(int, int)> capture = [&](int r, int c)
        {
            if (r < 0 || r == m || c < 0 || c == n || grid[r][c] == 0 || visited[r][c] == 1)
                return;
            visited[r][c] = 1;
            capture(r + 1, c);
            capture(r - 1, c);
            capture(r, c + 1);
            capture(r, c - 1);
        };

        for (int r = 0; r < m; r++)
        {
            capture(r, 0);
            capture(r, n - 1);
        }
        for (int c = 0; c < n; c++)
        {
            capture(0, c);
            capture(m - 1, c);
        }
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 && grid[i][j] != visited[i][j])
                    count++;
            }
        }
        return count;
    }
};