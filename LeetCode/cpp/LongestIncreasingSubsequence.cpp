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

class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n^2)
    // Bottom-up Dynamic Programming (Tabulation)
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int prev = -1; prev < n; prev++)
            {
                if (i == n)
                    dp[i][prev + 1] = 0;
                else
                {
                    int notTake = 0 + dp[i + 1][prev + 1];
                    int take = INT_MIN;
                    if (prev == -1 || nums[i] > nums[prev])
                        take = 1 + dp[i + 1][i + 1];
                    dp[i][prev + 1] = max(notTake, take);
                }
            }
        }
        return dp[0][0];
    }
};

class Solution
{
    // Time Complexity: O(n^2)
    // Space Complexity: O(n)
    // Bottom-up Dynamic Programming (Tabulation)
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[i] < nums[j])
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

/*
Explanation For the Tabulation Approach:
1. Create a vector dp of size n and initialize all elements to 1.
2. Iterate from n - 1 to 0.
3. For each i, iterate from i + 1 to n.
4. If nums[i] < nums[j], update dp[i] to max(dp[i], 1 + dp[j]).
5. Return the maximum element in dp.
*/

