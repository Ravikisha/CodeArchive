class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int maxProduct(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        int ans = nums[0];
        int _max = ans, _min = ans;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] < 0)
            {
                swap(_max, _min);
            }
            _max = max(nums[i], nums[i] * _max);
            _min = min(nums[i], nums[i] * _min);
            ans = max(_max, ans);
        }
        return ans;
    }
};

/*
Explaination:
1. If the current element is negative, we swap the _max and _min values.
2. We update the _max and _min values.
3. We update the ans value.
4. We return the ans value.


Example 1:
nums = [2, 3, -2, 4]
Output: 6

Step 1: nums[0] = 2, _max = 2, _min = 2, ans = 2
Step 2: nums[1] = 3, _max = 6, _min = 3, ans = 6
Step 3: nums[2] = -2, _max = -2, min = -12, ans = 6
Step 4: nums[3] = 4, _max = 4, _min = -48, ans = 6
*/