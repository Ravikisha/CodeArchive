class Solution
{
    // Time Complexity: O(n!)
    // Space Complexity: O(n)
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> pers;
        vector<int> per;
        function<void()> backtrack = [&]()
        {
            if (per.size() == nums.size())
                pers.push_back(per);
            else
            {
                for (int e : nums)
                {
                    if (find(per.begin(), per.end(), e) != per.end())
                        continue;
                    per.push_back(e);
                    backtrack();
                    per.pop_back();
                }
            }
        };
        backtrack();
        return pers;
    }
};