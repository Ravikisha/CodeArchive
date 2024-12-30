class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
    // Memoization based recursive solution
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        function<int(int, int)> dfs = [&](int r, int c)
        {
            if (r == m || c == n || r < 0 || c < 0)
                return 0;
            if (r == m - 1 && c == n - 1)
                return 1;
            if (dp[r][c] != -1)
                return dp[r][c];
            return dp[r][c] = dfs(r + 1, c) + dfs(r, c + 1);
        };
        return dfs(0, 0);
    }
};

class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(m*n)
    // Tabulation based iterative solution
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        dp[0][0] = 1;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[i - 1][j];
                    if (j > 0)
                        left = dp[i][j - 1];
                    dp[i][j] = up + left;
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

class Solution
{
    // Time Complexity: O(m*n)
    // Space Complexity: O(n)
    // Tabulation based iterative solution with optimized space
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 0);
        for (int i = 0; i < m; i++)
        {
            vector<int> temp(n, 0);
            for (int j = 0; j < n; j++)
            {
                if (i == 0 && j == 0)
                    temp[i] = 1;
                else
                {
                    int up = 0, left = 0;
                    if (i > 0)
                        up = dp[j];
                    if (j > 0)
                        left = temp[j - 1];
                    temp[j] = up + left;
                }
            }
            dp = temp;
        }
        return dp[n - 1];
    }
};