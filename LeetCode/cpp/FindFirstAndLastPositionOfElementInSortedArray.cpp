class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);  // Initialize result with [-1, -1]
        
        // Helper lambda function to find the first occurrence of target
        auto findFirst = [&](int target) -> int {
            int left = 0, right = nums.size() - 1, index = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    index = mid;  // Save the index, but continue searching left
                    right = mid - 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return index;
        };

        // Helper lambda function to find the last occurrence of target
        auto findLast = [&](int target) -> int {
            int left = 0, right = nums.size() - 1, index = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target) {
                    index = mid;  // Save the index, but continue searching right
                    left = mid + 1;
                } else if (nums[mid] < target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            return index;
        };

        // Find the first and last occurrence of the target
        result[0] = findFirst(target);
        if (result[0] != -1) {
            result[1] = findLast(target);
        }

        return result;
    }
};