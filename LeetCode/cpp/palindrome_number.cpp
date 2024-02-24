class Solution {
    public boolean isPalindrome(int x) {
       if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
    }

    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertedNumber || x == revertedNumber / 10; 
    }
}

// cpp result
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