class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
public:
    int dfs(int i, int j, vector<vector<int>> &grid,
            vector<vector<bool>> &searched)
    {
        // Boundary conditions
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            searched[i][j] || grid[i][j] == 0)
            return 0;

        // Mark cell as searched
        searched[i][j] = true;

        // Explore all four directions and sum the area
        return 1 + dfs(i + 1, j, grid, searched) +
               dfs(i - 1, j, grid, searched) + dfs(i, j + 1, grid, searched) +
               dfs(i, j - 1, grid, searched);
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int maxArea = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> searched(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // Start a DFS if we find an unsearched land cell
                if (grid[i][j] == 1 && !searched[i][j])
                {
                    int area = dfs(i, j, grid, searched);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};