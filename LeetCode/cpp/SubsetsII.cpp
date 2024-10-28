class Solution
{
    // Time Complexity: O(n * 2^n)
    // Space Complexity: O(n)
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> subset;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        function<void(int)> backtrack = [&](int i)
        {
            if (i == n)
            {
                result.push_back(subset);
                return;
            }
            // All subset that include nums[i]
            subset.push_back(nums[i]);
            backtrack(i + 1);
            subset.pop_back();
            // all the subset that don't include nums[i]
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;
            backtrack(i + 1);
        };
        backtrack(0);
        return result;
    }
};