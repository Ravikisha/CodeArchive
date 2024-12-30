class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int robLinear(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0; // Handle empty input case
        int prev1 = nums[0];
        int prev2 = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            prev2 = prev1;
            prev1 = max(pick, notPick);
        }
        return prev1;
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0]; // Handle single house case

        // If there are at least two houses, we can use the two cases:
        vector<int> temp1(nums.begin() + 1, nums.end()); // Exclude the first house
        vector<int> temp2(nums.begin(), nums.end() - 1); // Exclude the last house
        return max(robLinear(temp1), robLinear(temp2));
    }
};
