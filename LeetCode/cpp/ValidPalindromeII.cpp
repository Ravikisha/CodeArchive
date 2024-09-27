class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    bool isPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        for(int i=0;i<s.size();i++){
            int j = s.size()-1-i;
            if(s[i] != s[j]){
                return isPalindrome(s, i+1, j) || isPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};