class Solution
{
    // Time Complexity: O(2^n)
    // Space Complexity: O(n)
public:
    void backtrack(vector<vector<int>> &ans, vector<int> &subset, vector<int> &nums, int start)
    {
        ans.push_back(subset);
        for (int i = start; i < nums.size(); i++)
        {
            subset.push_back(nums[i]);
            backtrack(ans, subset, nums, i + 1);
            subset.pop_back();
        }
    };

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        backtrack(ans, subset, nums, 0);

        return ans;
    }
};

// Another solution for neetcode
class Solution
{
    // Time complexity: O(2^n)
    // Space complexity: O(n)
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        function<void(int)> dfs = [&](int i)
        {
            if (i >= nums.size())
            {
                ans.push_back(subset);
                return;
            }
            // decide whether to choose nums[i]
            subset.push_back(nums[i]);
            dfs(i + 1);
            // decide whether not to choose nums[i]
            subset.pop_back();
            dfs(i + 1);
        };
        dfs(0);
        return ans;
    }
};

class Solution
{
    // Time complexity: O(2^n)
    // Space complexity: O(n)
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++)
        {
            vector<int> list;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    list.push_back(nums[j]);
            }
            result.push_back(list);
        }
        return result;
    }
};