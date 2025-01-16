class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int l = 0, maxLen = 0;
        int n = nums.size();
        int ones = 0;
        for (int r = 0; r < n; r++)
        {
            if (nums[r] == 1)
                ones++;
            while ((r - l + 1) - ones > k)
            {
                if (nums[l] == 1)
                    ones--;
                l++;
            }
            if ((r - l + 1) - ones <= k)
            {
                maxLen = max(maxLen, r - l + 1);
            }
        }
        return maxLen;
    }
};