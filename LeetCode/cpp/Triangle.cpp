class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
    // Tabulation based iterative solution
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + dp[i + 1][j];
                int dg = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};

class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    // Tabulation based iterative solution with optimized space
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n, 0);
        for (int i = 0; i < n; i++)
        {
            dp[i] = triangle[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            vector<int> temp(n, 0);
            for (int j = i; j >= 0; j--)
            {
                int d = triangle[i][j] + dp[j];
                int dg = triangle[i][j] + dp[j + 1];
                temp[j] = min(d, dg);
            }
            dp = temp;
        }
        return dp[0];
    }
};