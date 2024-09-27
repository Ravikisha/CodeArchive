class Solution {
    // Time Complexity: O(logn)
    // Space Complexity: O(1)
public:
    int arrangeCoins(int n) {
        long n_long = (long) n;
        long left = 1, right = n_long;
        
        while(left <= right) {
            long mid = left + (right - left) / 2;
            
            if(mid * (mid + 1) / 2 <= n_long) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            
        }
        return (int) left - 1;
    }
};

// Another Solution
class Solution {
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int arrangeCoins(int n) {
        return (int) ((sqrt(1 + 8 * (long) n) - 1) / 2);
    }
};
