class Solution
{
    // Time Complexity: O(n * amount)
    // Space Complexity: O(amount)
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        vector<int> cur(amount + 1, 0);
        for (int t = 0; t <= amount; t++)
        {
            if (t % coins[0] == 0)
                dp[t] = t / coins[0];
            else
                dp[t] = 1e9;
        }
        for (int i = 1; i < n; i++)
        {
            for (int t = 0; t <= amount; t++)
            {
                int notTake = 0 + dp[t];
                int take = 1e9;
                if (coins[i] <= t)
                    take = 1 + cur[t - coins[i]];
                cur[t] = min(take, notTake);
            }
            dp = cur;
        }
        int ans = dp[amount];
        if (ans >= 1e9)
            return -1;
        return ans;
    }
};