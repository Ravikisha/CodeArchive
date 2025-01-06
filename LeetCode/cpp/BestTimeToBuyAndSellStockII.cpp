class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Bottom-up Dynamic Programming (Tabulation)
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<long>> dp(n + 1, vector<long>(2, 0));
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
                    profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
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
    // Bottom-up Dynamic Programming (Tabulation)
    // Space Optimized
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> dp(2, 0), curr(2, 0);
        dp[0] = dp[1] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[i] + dp[0], 0 + dp[1]);
                }
                else
                {
                    profit = max(prices[i] + dp[1], 0 + dp[0]);
                }
                curr[buy] = profit;
            }
            dp = curr;
        }
        return dp[1];
    }
};

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Bottom-up Dynamic Programming (Tabulation)
    // Space Optimized (Further)
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int aheadNotBuy, aheadBuy, curBuy, curNotBuy;
        aheadNotBuy = aheadBuy = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            // sell
            curNotBuy = max(prices[i] + aheadBuy, 0 + aheadNotBuy);
            // buy
            curBuy = max(-prices[i] + aheadNotBuy, 0 + aheadBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
};