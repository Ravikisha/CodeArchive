class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size() + 1;
        vector<int> f(n, 0);

        for(auto i : nums)
            ++f[i];

        for(int i = 1; i < n; i++)
            if(f[i] == 2)
                ans.push_back(i);

        return ans;
    }
};