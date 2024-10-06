class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int pivotIndex(vector<int> &nums)
    {
        int total = reduce(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int rightSum = total - nums[i] - leftSum;
            if (leftSum == rightSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};