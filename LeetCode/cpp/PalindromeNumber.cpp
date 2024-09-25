// Cpp Solution
// Time: O(log10(x)), Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        long long pali = 0, temp = x;
        while(temp != 0){
            pali = pali*10+(temp%10);
            temp /= 10;
        }   
        return pali==x;
    }
};