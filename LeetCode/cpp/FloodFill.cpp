class Solution
{
    // Time Complexity: O(N*M)
    // Space Complexity: O(N*M)
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int rows = image.size();
        int cols = image[0].size();
        int startColor = image[sr][sc]; // Store the starting pixel color

        if (startColor == color)
            return image; // Avoid infinite recursion if the target color is the same

        function<void(int, int)> dfs = [&](int r, int c)
        {
            if (r < 0 || c < 0 || r >= rows || c >= cols || image[r][c] != startColor)
                return;
            image[r][c] = color;
            dfs(r + 1, c);
            dfs(r - 1, c);
            dfs(r, c + 1);
            dfs(r, c - 1);
        };

        dfs(sr, sc);
        return image;
    }
};