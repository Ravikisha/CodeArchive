class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int minFlips(string s) {
        int n = s.size();
        int cnt = 0;
        string target = "01";
        
        // Calculate mismatches with the pattern starting with '0' and '1'
        for (int i = 0; i < n; ++i) {
            if (s[i] != target[i % 2]) {
                ++cnt;
            }
        }
        
        int minFlips = min(cnt, n - cnt);  // Initialize with minimum flips
        for (int i = 0; i < n; ++i) {
            // Sliding window to simulate string rotation
            if (s[i] != target[i % 2]) {
                --cnt;
            }
            if (s[i] != target[(i + n) % 2]) {
                ++cnt;
            }
            minFlips = min(minFlips, min(cnt, n - cnt));  // Track the minimum flips
        }

        return minFlips;
    }
};

/*
Explanation:
1. Calculate the number of mismatches with the pattern starting with '0' and '1'.
2. Initialize the minimum flips with the minimum of the number of mismatches and the number of matches.
3. Slide the window to simulate string rotation.
4. Track the minimum flips.
5. Return the minimum flips.

Example:
s = "111000"
target = "01"
n = 6
cnt = 3
minFlips = 3
i = 0
    s[0] = '1' != target[0 % 2] = '0'
    cnt = 2
    s[0] = '1' != target[(0 + 6) % 2] = '1'
    cnt = 3
    minFlips = min(3, 6 - 3) = 3
i = 1
    s[1] = '1' != target[1 % 2] = '1'
    cnt = 3
    s[1] = '1' != target[(1 + 6) % 2] = '0'
    cnt = 2
    minFlips = min(2, 6 - 2) = 2
i = 2
    s[2] = '1' != target[2 % 2] = '0'
    cnt = 1
    s[2] = '1' != target[(2 + 6) % 2] = '1'
    cnt = 2
    minFlips = min(2, 6 - 2) = 2
i = 3
    s[3] = '0' != target[3 % 2] = '1'
    cnt = 3
    s[3] = '0' != target[(3 + 6) % 2] = '0'
    cnt = 3
    minFlips = min(3, 6 - 3) = 3
i = 4
    s[4] = '0' != target[4 % 2] = '0'
    cnt = 3
    s[4] = '0' != target[(4 + 6) % 2] = '1'
    cnt = 4
    minFlips = min(3, 6 - 3) = 3
i = 5
    s[5] = '0' != target[5 % 2] = '1'
    cnt = 4
    s[5] = '0' != target[(5 + 6) % 2] = '0'
    cnt = 4
    minFlips = min(3, 6 - 3) = 3
minFlips = 3
Return 3
*/