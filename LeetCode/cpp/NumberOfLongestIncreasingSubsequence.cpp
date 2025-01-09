class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    // Bottom-Up Approach (Tabulation)
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        int maxi = 1;
        vector<int> dp(n, 1), count(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i] && 1 + dp[j] > dp[i])
                {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
                else if (nums[j] < nums[i] && 1 + dp[j] == dp[i])
                {
                    count[i] += count[j];
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }
        int maxCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
                maxCount += count[i];
        }
        return maxCount;
    }
};