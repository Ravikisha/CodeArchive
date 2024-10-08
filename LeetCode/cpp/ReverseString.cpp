class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i < j){
            swap(s[i], s[j]);
            i++, j--;
        }
    }
};