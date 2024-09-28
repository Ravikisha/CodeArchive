class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isSubsequence(string s, string t) {
        if(s.length() == 0) return true;
        int idx = 0;
        for(const char& c: t){
            if(c == s[idx]){
                idx++;
            }
            if(idx == s.length()) return true;
        }
        return false;
    }
    
};