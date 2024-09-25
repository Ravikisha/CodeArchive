class Solution {
    // Time complexity: O(n)
    // Space complexity: O(1)
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Ensure k is within bounds
        if (k == 0) return;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.end());
    }
};