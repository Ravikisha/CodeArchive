class Solution {
    // Time Complexity: O(logn)
    // Space Complexity: O(1)
public:
    int mySqrt(int x) {
        int floor = 0; // Variable to store the largest integer less than or equal to the square root
        int left = 1, right = x; // Initialize left and right pointers for binary search
        while (left <= right) {
            int mid = ((right - left) / 2) + left; // Calculate mid point
            if (mid == x / mid) {
                return mid; // Perfect square case
            }
            if (mid < x / mid) {
                floor = mid; // Update floor if mid is a potential candidate
                left = mid + 1; // Move left pointer up
            } else {
                right = mid - 1; // Move right pointer down
            }
        }
        return floor; // Return the floor value found
    }
};