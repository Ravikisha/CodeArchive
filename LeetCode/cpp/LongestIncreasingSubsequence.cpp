class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
    // Top-down Dynamic Programming (Memoization)
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        function<int(int, int)> backtracking = [&](int i, int prev)
        {
            if (i == n)
                return 0;
            if (dp[i][prev + 1] != -1)
                return dp[i][prev + 1];
            int notTake = 0 + backtracking(i + 1, prev);
            int take = INT_MIN;
            if (prev == -1 || nums[i] > nums[prev])
                take = 1 + backtracking(i + 1, i);
            return dp[i][prev + 1] = max(notTake, take);
        };
        return backtracking(0, -1);
    }
};