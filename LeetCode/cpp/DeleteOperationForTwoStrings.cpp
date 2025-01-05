class Solution
{
    // Time Complexity: O(n * m)
    // Space Complexity: O(min(n, m))
    // Bottom-up Dynamic Programming (Tabulation)
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            int prev = 0; // Store dp[j - 1] from the previous row
            for (int j = 1; j <= m; j++)
            {
                int temp = dp[j]; // Temporarily store the current dp[j] before
                                  // updating
                if (word1[i - 1] == word2[j - 1])
                    dp[j] = 1 + prev; // Use prev instead of dp[j - 1]
                else
                    dp[j] = max(dp[j], dp[j - 1]);
                prev = temp; // Update prev for the next iteration
            }
        }
        // int numberOfInseration = m - dp[m];
        // int numberOfDeletion = n - dp[m];
        return n + m - 2 * dp[m];
    }
};