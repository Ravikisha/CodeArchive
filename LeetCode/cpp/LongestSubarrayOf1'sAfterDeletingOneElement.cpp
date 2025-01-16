class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int longestSubarray(vector<int> &nums)
    {
        int len = 0;
        int n = nums.size();
        int l = 0;
        int ones = 0;
        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 1)
                ones++;
            while ((r - l + 1) - ones > 1)
            {
                if (nums[l] == 1)
                    ones--;
                l++;
            }
            len = max(len, r - l + 1);
        }
        return len - 1;
    }
};