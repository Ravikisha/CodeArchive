class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Bottom-up Dynamic Programming
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<long>> dp(n + 2, vector<long>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                long profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                }
                else
                {
                    profit = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Bottom-up Dynamic Programming
    // Space Optimized
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> front2(2, 0), front1(2, 0), curr(2, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            curr[1] = max(-prices[i] + front1[0], 0 + front1[1]);
            curr[0] = max(prices[i] + front2[1], 0 + front1[0]);
            front2 = front1;
            front1 = curr;
        }
        return curr[1];
    }
};