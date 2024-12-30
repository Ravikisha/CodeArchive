class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Bottom Up Approach (Memoization)
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        function<int(int)> backtrack = [&](int i)
        {
            if (i == 0)
                return nums[i];
            if (i < 0)
                return 0;
            if (dp[i] != -1)
                return dp[i];
            int pick = nums[i] + backtrack(i - 2);
            int notPick = 0 + backtrack(i - 1);
            return dp[i] = max(pick, notPick);
        };
        return backtrack(n - 1);
    }
};

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
    // Bottom Up Approach (Tabulation)
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
            {
                pick += dp[i - 2];
            }
            int notPick = 0 + dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    // Bottom Up Approach
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;
        int result = nums[0];
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i] + prev2;
            int notPick = 0 + prev1;
            result = max(pick, notPick);
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
};