class Solution
{
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
};

// Optimized Solution
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n);
        int l = 0, r = n - 1;
        int idx = n - 1;
        while (l <= r)
        {
            if (nums[l] * nums[l] > nums[r] * nums[r])
            {
                res[idx--] = nums[l] * nums[l];
                l++;
            }
            else
            {
                res[idx--] = nums[r] * nums[r];
                r--;
            }
        }
        return res;
    }
};