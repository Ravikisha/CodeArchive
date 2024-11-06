class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int rows = heights.size(), cols = heights[0].size();
        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        function<void(int, int, vector<vector<bool>> &visited, int)> dfs =
            [&](int r, int c, vector<vector<bool>> &visited, int prevHeight)
        {
            if (r < 0 || r == rows || c < 0 || c == cols || visited[r][c] ||
                heights[r][c] < prevHeight)
                return;
            visited[r][c] = true;
            dfs(r + 1, c, visited, heights[r][c]);
            dfs(r - 1, c, visited, heights[r][c]);
            dfs(r, c - 1, visited, heights[r][c]);
            dfs(r, c + 1, visited, heights[r][c]);
        };

        for (int c = 0; c < cols; c++)
        {
            dfs(0, c, pac, heights[0][c]);
            dfs(rows - 1, c, atl, heights[rows - 1][c]);
        }
        for (int r = 0; r < rows; r++)
        {
            dfs(r, 0, pac, heights[r][0]);
            dfs(r, cols - 1, atl, heights[r][cols - 1]);
        }
        vector<vector<int>> result;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (pac[r][c] && atl[r][c])
                {
                    result.push_back({r, c});
                }
            }
        }
        return result;
    }
};