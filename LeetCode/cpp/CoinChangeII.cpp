class Solution
{
    // Time Complexity: O(n * amount)
    // Space Complexity: O(amount)
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<unsigned> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < n; ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};