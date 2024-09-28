class Solution
{
    // Time complexity: O(n)
    // Space complexity: O(1)
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        int target = reduce(nums.begin(), nums.end(), 0) - x;
        int max_window = -1;
        int cur_sum = 0;
        int l = 0;
        for (int r = 0; r < n; r++)
        {
            cur_sum += nums[r];
            while (l <= r && cur_sum > target)
            {
                cur_sum -= nums[l++];
            }
            if (cur_sum == target)
            {
                max_window = max(max_window, r - l + 1);
            }
        }
        if (max_window == -1)
        {
            return -1;
        }
        return n - max_window;
    }
};