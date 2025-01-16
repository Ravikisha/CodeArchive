class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    int maxOperations(vector<int> &nums, int k)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        int result = 0;
        while (l < r)
        {
            int sum = nums[l] + nums[r];
            if (sum == k)
            {
                result++;
                l++;
                r--;
            }
            else if (sum > k)
            {
                r--;
            }
            else
            {
                l++;
            }
        }
        return result;
    }
};