class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(2n)
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // dynamic resizing take more time
        int n = nums.size();
        vector<int> result(2 * n); // Create a vector of double the size
        
        for (int i = 0; i < n; ++i) {
            result[i] = nums[i];
            result[i + n] = nums[i]; // Concatenate nums to itself
        }
        
        return result;
    }
};