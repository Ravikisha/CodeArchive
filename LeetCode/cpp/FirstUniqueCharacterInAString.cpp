// Better Solution
class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int firstUniqChar(string s) {
        vector<int> f(26, 0);

        for(auto i : s)
            ++f[i - 'a'];

        for(int i = 0; i < s.size(); i++){
            if(f[s[i] - 'a'] == 1)
                return i;
        }

        return -1;
    }
};

// Optimal Solution
class Solution {
    /*
    Instead of making two passes—one to count frequencies and one to check for the first unique character—you can use a hash map (or an array) to track the index of each character during the first pass itself. This reduces the need for two passes over the string. However, this improvement is marginal, and for small inputs, the difference won't be noticeable. The overall time complexity remains the same.
    */
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int firstUniqChar(string s) {
        vector<int> index(26, -1); // Store index or -1 if seen more than once
        
        for (int i = 0; i < s.size(); i++) {
            int charIdx = s[i] - 'a';
            if (index[charIdx] == -1) {
                index[charIdx] = i; // First occurrence
            } else if (index[charIdx] >= 0) {
                index[charIdx] = -2; // Mark as seen more than once
            }
        }

        int firstUnique = s.size();
        for (int i = 0; i < 26; i++) {
            if (index[i] >= 0) {
                firstUnique = min(firstUnique, index[i]);
            }
        }

        return (firstUnique == s.size()) ? -1 : firstUnique;
    }
};