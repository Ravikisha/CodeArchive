class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isPalindrome(string s) {
        if(s.length() == 0) return true;
        int i=0,j=s.length()-1;
        while (i < j) {
            if (!isalnum(s[i])) {
                ++i;
            } else if (!isalnum(s[j])) {
                --j;
            } else if (tolower(s[i]) != tolower(s[j])) {
                return false;
            } else {
                ++i, --j;
            }
        }
        return true;
    }
};