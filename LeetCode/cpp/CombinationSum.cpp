class Solution
{
    // Time complexity: O(2^n)
    // Space complexity: O(n)
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> subset;

        function<void(int, int)> backtrack = [&](int i, int target)
        {
            if (i == candidates.size())
            {
                if (target == 0)
                {
                    ans.push_back(subset);
                }
                return;
            }
            if (candidates[i] <= target)
            {
                // decide whether to choose candidates[i]
                subset.push_back(candidates[i]);
                backtrack(i, target - candidates[i]);
                subset.pop_back();
            }
            // decide whether not to choose candidates[i]
            backtrack(i + 1, target);
        };
        backtrack(0, target);
        return ans;
    }
};