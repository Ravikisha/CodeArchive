class Solution {
    // Time Complexity: O(n), Space Complexity: O(1)
public:
    string reverseWords(string s) {
        int n = s.size();
        int i=0;
        int prev = 0;
        while(i <= n){
            if(s[i] == ' ' || i==n){
                reverse(s.begin()+prev, s.begin()+i);
                prev = i+1;
            }
            i++;
        }
        return s;
    }
};