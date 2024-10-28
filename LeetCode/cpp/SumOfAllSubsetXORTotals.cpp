// Iterative approach
class Solution
{
    // Time complexity: O(2^n)
    // Space complexity: O(1)
public:
    int subsetXORSum(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < 1 << n; ++i)
        {
            int s = 0;
            for (int j = 0; j < n; ++j)
            {
                if (i >> j & 1)
                {
                    s ^= nums[j];
                }
            }
            ans += s;
        }
        return ans;
    }
};

// Recursive approach
class Solution
{
    // Time complexity: O(2^n)
    // Space complexity: O(n)
public:
    int subsetXORSum(vector<int> &nums)
    {
        function<int(int, int)> dfs = [&](int i, int total)
        {
            if (i == nums.size())
                return total;
            return dfs(i + 1, total ^ nums[i]) + dfs(i + 1, total);
        };
        return dfs(0, 0);
    }
};