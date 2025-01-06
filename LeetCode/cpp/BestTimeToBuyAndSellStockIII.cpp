class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Bottom-up Dynamic Programming (Tabulation)
    // Space Optimized
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= 2; cap++)
                {
                    if (buy == 1)
                    {
                        curr[buy][cap] =
                            max(-prices[i] + dp[0][cap], 0 + dp[1][cap]);
                    }
                    else
                    {
                        curr[buy][cap] =
                            max(prices[i] + dp[1][cap - 1], 0 + dp[0][cap]);
                    }
                }
            }
            dp = curr;
        }
        return dp[1][2];
    }
};