class Solution
{
    // Time Complexity: O(m X n)
    // Space Complexity: O(1)
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        if (m == 0)
            return 0;
        int n = grid[0].size();
        if (n == 0)
            return 0;

        vector<vector<int>> dirs = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1}};

        int ans = 0;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    ans += 4;
                    for (vector<int> &dir : dirs)
                    {
                        int ni = i + dir[0];
                        int nj = j + dir[1];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj])
                        {
                            --ans;
                        }
                    }
                }
            }
        }

        return ans;
    }
};

// DFS approach
class Solution
{
    // Time Complexity: O(m * n)
    // Space Complexity: O(1)
public:
    int islandPerimeter(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        // Lambda function for DFS
        function<int(int, int)> dfs = [&](int i, int j)
        {
            // Out-of-bounds or water cell contributes to the perimeter
            if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
                return 1;
            // If cell is already visited, it does not contribute to the perimeter
            if (grid[i][j] == -1)
                return 0;

            // Mark cell as visited
            grid[i][j] = -1;

            // Sum up the perimeter contributions from each direction
            int perim = dfs(i, j + 1);
            perim += dfs(i + 1, j);
            perim += dfs(i, j - 1);
            perim += dfs(i - 1, j);

            return perim;
        };

        // Start DFS from the first land cell found
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) // Found a land cell
                    return dfs(i, j);
            }
        }
        return 0;
    }
};