class Solution
{
    // Time Complexity: O(n * 2^n)
    // Space Complexity: O(n)
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> subset;
        function<void(int, vector<int>)> backtrack = [&](int start,
                                                         vector<int> comb)
        {
            if (comb.size() == k)
            {
                ans.push_back(comb);
                return;
            }
            for (int i = start; i <= n; i++)
            {
                // decide whether to choose i
                comb.push_back(i);
                // choose i and move to the next
                backtrack(i + 1, comb);
                // decide whether not to choose i
                comb.pop_back();
            }
        };
        backtrack(1, {});
        return ans;
    }
};