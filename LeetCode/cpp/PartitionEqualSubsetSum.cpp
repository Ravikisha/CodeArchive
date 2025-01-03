class Solution
{
    // Time Complexity: O(n*sum)
    // Space Complexity: O(sum)
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = reduce(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0)
            return false;
        int target = sum / 2;
        int n = nums.size();
        vector<bool> dp(target + 1, false);
        vector<bool> curr(target + 1, false);
        dp[0] = curr[0] = true;
        if (nums[0] <= target)
            dp[nums[0]] = true;
        for (int i = 1; i < n; i++)
        {
            for (int tar = 1; tar <= target; tar++)
            {
                bool notTake = dp[tar];
                bool take = false;
                if (nums[i] <= tar)
                    take = dp[tar - nums[i]];
                curr[tar] = notTake | take;
            }
            dp = curr;
        }
        return dp[target];
    }
};