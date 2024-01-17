class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        for (int i = 0; i < s.length(); i++) {
            string s1 = checkPalindrome(s, i, i);
            string s2 = checkPalindrome(s, i, i + 1);
            if (s1.length() > res.length()) {
                res = s1;
            }
            if (s2.length() > res.length()) {
                res = s2;
            }
        }
        return res;
    }
    string checkPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
};