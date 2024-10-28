class Solution
{
    // Time Complexity: O(nlogn+2^n)
    // Space Complexity: O(O(2^n*n))
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        function<void(int, int)> backtrack = [&](int i, int target)
        {
            if (target == 0)
                ans.push_back(subset);
            if (target <= 0)
                return;
            int prev = -1;
            for (; i < n; i++)
            {
                // Skip 
                if (candidates[i] == prev)
                    continue;
                subset.push_back(candidates[i]);
                backtrack(i + 1, target - candidates[i]);
                subset.pop_back();
                prev = candidates[i];
            }
        };

        backtrack(0, target);
        return ans;
    }
};