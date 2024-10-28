// Time Limit Exceeded
class Solution
{
    // Time complexity: O(k * 2^N), where N is the length of nums
    // Space complexity: O(N)
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is not divisible by k, we can't partition
        if (totalSum % k != 0)
            return false;

        int target = totalSum / k;             // Target sum for each subset
        vector<bool> used(nums.size(), false); // Track used elements
        sort(nums.begin(), nums.end());        // Sort in ascending order for efficiency

        // Early exit if the largest number is greater than the target
        if (nums.back() > target)
            return false;

        // Backtracking function to try forming subsets
        function<bool(int, int)> backtrack = [&](int currentSum, int count)
        {
            // If we formed k-1 subsets, the last one is guaranteed to be valid
            if (count == k - 1)
                return true; // All subsets filled successfully

            // If current sum is equal to target, reset to form the next subset
            if (currentSum == target)
            {
                return backtrack(0, count + 1);
            }

            for (int i = 0; i < nums.size(); i++)
            {
                // Skip used numbers or if adding the current number exceeds the target
                if (used[i] || currentSum + nums[i] > target)
                    continue;

                used[i] = true; // Mark as used
                // Recur with the updated sum
                if (backtrack(currentSum + nums[i], count))
                    return true;
                used[i] = false; // Backtrack
            }
            return false; // No valid partition found
        };

        return backtrack(0, 0); // Start backtracking
    }
};