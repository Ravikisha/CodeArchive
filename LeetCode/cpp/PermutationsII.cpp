class Solution
{
    // Time Complexity: O(n*n!)
    // Space Complexity: O(n*n!)

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> pers;
        vector<int> per;
        vector<bool> used(nums.size(), false);

        // Sort to easily skip duplicates
        sort(nums.begin(), nums.end());

        function<void()> backtrack = [&]()
        {
            if (per.size() == nums.size())
            {
                pers.push_back(per);
                return;
            }

            for (int i = 0; i < nums.size(); i++)
            {
                // Skip used elements or duplicates (when current element is the same as the previous one and the previous one was not used)
                if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]))
                    continue;

                // Mark the current element as used and add it to the permutation
                used[i] = true;
                per.push_back(nums[i]);

                // Recurse
                backtrack();

                // Undo the choice
                used[i] = false;
                per.pop_back();
            }
        };

        backtrack();
        return pers;
    }
};