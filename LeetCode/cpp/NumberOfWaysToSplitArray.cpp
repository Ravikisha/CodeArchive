class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int waysToSplitArray(vector<int> &nums)
    {
        int n = nums.size();
        long long rightSum = 0;
        for (int i = 0; i < n; i++)
            rightSum += nums[i];
        long long leftSum = 0;
        int result = 0;
        for (int i = 0; i < n - 1; i++)
        {
            leftSum += nums[i];
            rightSum -= nums[i];
            if (leftSum >= rightSum)
                result++;
        }
        return result;
    }
};