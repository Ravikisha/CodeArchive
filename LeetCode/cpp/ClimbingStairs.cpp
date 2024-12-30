class Solution
{
    // Time complexity: O(n)
    // Space complexity: O(n)
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // base case
        dp[1] = 1; // base case
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// Another Solution with Less Space Complexity
class Solution
{
    // Time complexity: O(n)
    // Space complexity: O(1)
public:
    int climbStairs(int n)
    {
        if (n <= 1)
            return 1;
        int prev1 = 1;
        int prev2 = 1;
        int result = 0;
        for (int i = 2; i <= n; i++)
        {
            result = prev1 + prev2;
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
};