class Solution
{
    // Time Complexity: O(n*sum)
    // Space Complexity: O(sum)
public:
    int findTargetSumWays(vector<int> &arr, int d)
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        const int MOD = 1e9 + 7; // To avoid overflow, use modulo operation.
        int n = arr.size();
        if (sum - d < 0 || (sum - d) % 2)
            return 0;
        int target = (sum - d) / 2;
        vector<int> dp(target + 1, 0);
        if (arr[0] == 0)
            dp[0] = 2;
        else
            dp[0] = 1;

        // Initialize the first element.
        if (arr[0] != 0 && arr[0] <= target)
            dp[arr[0]] += 1;

        for (int i = 1; i < n; i++)
        {
            for (int tar = target; tar >= 0; tar--)
            {
                if (arr[i] <= tar)
                {
                    dp[tar] = (dp[tar] + dp[tar - arr[i]]) % MOD;
                }
            }
        }

        return dp[target];
    }
};