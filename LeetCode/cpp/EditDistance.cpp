class Solution
{
    // Time Complexity: O(n*m)
    // Space Complexity: O(n*m)
    // Bottom-up Dynamic Programming (Tabulation)
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j],        // insertion
                                       min(dp[i][j - 1],    // deletion
                                           dp[i - 1][j - 1] // replace
                                           ));
                }
            }
        }

        return dp[n][m];
    }
};

class Solution
{
    // Time Complexity: O(n*m)
    // Space Complexity: O(m)
    // Bottom-up Dynamic Programming (Tabulation) with Space Optimization
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m + 1, 0), curr(m + 1, 0);
        for (int j = 0; j <= m; j++)
            dp[j] = j;

        for (int i = 1; i <= n; i++)
        {
            curr[0] = i;
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    curr[j] = dp[j - 1];
                }
                else
                {
                    curr[j] = 1 + min(dp[j],           // deletion
                                      min(curr[j - 1], // insertion
                                          dp[j - 1]    // replace
                                          ));
                }
            }
            dp = curr;
        }

        return dp[m];
    }
};