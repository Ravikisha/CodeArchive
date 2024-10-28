class Solution
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(n)
public:
    int beautifulSubsets(vector<int> &nums, int k)
    {
        int ans = -1;        // Initialize `ans` to -1 to exclude the empty subset in the final count.
        int cnt[1010]{};     // Array `cnt` to track the count of each number in the subset.
        int n = nums.size(); // `n` is the number of elements in the `nums` vector.

        // Define a recursive function `dfs` to explore all subsets.
        function<void(int)> dfs = [&](int i)
        {
            // Base case: If we reach the end of `nums`, increment `ans` and return.
            if (i >= n)
            {
                ++ans; // Increase `ans` since a valid subset is found.
                return;
            }

            // Recursive call to explore the subset without including `nums[i]`.
            dfs(i + 1);

            // Check if `nums[i]` can be added to the current subset.
            // `ok1` is true if `nums[i] + k` is out of bounds or `cnt[nums[i] + k]` is zero,
            // meaning there is no element in the subset that conflicts with `nums[i] + k`.
            bool ok1 = nums[i] + k >= 1010 || cnt[nums[i] + k] == 0;

            // `ok2` is true if `nums[i] - k` is out of bounds or `cnt[nums[i] - k]` is zero,
            // meaning there is no element in the subset that conflicts with `nums[i] - k`.
            bool ok2 = nums[i] - k < 0 || cnt[nums[i] - k] == 0;

            // If both `ok1` and `ok2` are true, we can include `nums[i]` in the subset.
            if (ok1 && ok2)
            {
                ++cnt[nums[i]]; // Add `nums[i]` to the subset.

                // Recurse with `nums[i]` included in the subset.
                dfs(i + 1);

                --cnt[nums[i]]; // Backtrack by removing `nums[i]` from the subset.
            }
        };

        // Start the recursive exploration from index 0.
        dfs(0);

        // Return the count of beautiful subsets found.
        return ans;
    }
};
