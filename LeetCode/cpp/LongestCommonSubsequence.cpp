class Solution
{
    // Time Complexity: O(n * m)
    // Space Complexity: O(n * m)
    // Bottom-up Dynamic Programming (Tabulation)
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int j = 0; j <= m; j++)
        {
            dp[0][j] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[n][m];
    }
};

class Solution
{
    // Time Complexity: O(n * m)
    // Space Complexity: O(min(n, m))
    // Bottom-up Dynamic Programming (Tabulation)
    // Space Optimized
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int n = text1.size();
        int m = text2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int prev = 0; // Store dp[j - 1] from the previous row
            for (int j = 1; j <= m; j++)
            {
                int temp = dp[j]; // Temporarily store the current dp[j] before
                                  // updating
                if (text1[i - 1] == text2[j - 1])
                    dp[j] = 1 + prev; // Use prev instead of dp[j - 1]
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp; // Update prev for the next iteration
            }
        }
        return dp[m];
    }
};