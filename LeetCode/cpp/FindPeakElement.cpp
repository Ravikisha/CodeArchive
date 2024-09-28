class Solution {
    // Time Complexity: O(log(n))
    // Space Complexity: O(1)
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + right >> 1;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

/*
Explanation:
1. Apply binary search to find the peak element.
2. If the mid element is greater than the mid + 1 element, then search in the left half.
3. If the mid element is less than or equal to the mid + 1 element, then search in the right half.
4. Return the left value.
*/