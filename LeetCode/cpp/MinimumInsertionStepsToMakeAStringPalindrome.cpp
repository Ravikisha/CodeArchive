class Solution
{
    // Time complexity: O(n^2)
    // Space complexity: O(n)
    // Bottom-up dynamic programming (tabulation)
public:
    int minInsertions(string s)
    {
        string text1 = s;
        reverse(s.begin(), s.end());
        string text2 = s;
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
        return s.size() - dp[m];
    }
};