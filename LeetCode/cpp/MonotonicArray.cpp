class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isMonotonic(vector<int> &nums)
    {
        int n = nums.size();
        bool increase = true, decrease = true;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i < n - 1 && !(nums[i] <= nums[i + 1]))
                increase = false;
            if (i < n - 1 && !(nums[i] >= nums[i + 1]))
                decrease = false;
        }
        return increase || decrease;
    }
};