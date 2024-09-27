// Better Solution
class Solution {
    // Time Complexity: O(n logn)
    // Space Complexity: O(n)
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int n = nums.size();
        int l = 0, r=n-1;
        while(res.size() != nums.size()){
            res.push_back(nums[l++]);
            if(l <= r)
                res.push_back(nums[r--]);
        }
        return res;
    }
};

// Optimal Solution
class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    vector<int> rearrangeArray(vector<int>& nums) {
       for(size_t i = nums.size()-1; i --> 0;) {
            if(i % 2 != (nums[i] > nums[i+1])) {
                swap(nums[i], nums[i+1]);
            }
        }
        return nums;
    }
};