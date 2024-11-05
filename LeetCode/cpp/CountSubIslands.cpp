class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
public:
    int countSubIslands(vector<vector<int>> &grid1,
                        vector<vector<int>> &grid2)
    {
        int rows = grid1.size(), cols = grid1[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        function<bool(int, int)> dfs = [&](int r, int c)
        {
            if (r < 0 || r == rows || c < 0 || c == cols || grid2[r][c] == 0 || visited[r][c])
                return true;

            visited[r][c] = true;
            bool result = (grid1[r][c] == 1);

            result &= dfs(r - 1, c);
            result &= dfs(r + 1, c);
            result &= dfs(r, c - 1);
            result &= dfs(r, c + 1);

            return result;
        };

        int count = 0;
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if (grid2[r][c] == 1 && !visited[r][c] && dfs(r, c))
                {
                    count++;
                }
            }
        }
        return count;
    }
};