class Solution {
public:
    int reverse(int x) {
        int result = 0;
        bool negative = false;
        if (x < 0) negative=true;
        x = abs(x);
        while(x!=0){
            int rem = x%10;
            x /= 10;

            if(result > INT_MAX/10 || result == INT_MAX && rem > 7) return 0;
            if(result < INT_MIN || result == INT_MIN && rem < -8) return 0;
            result = result*10+rem;

        }
        if (negative){
            result = -result;
        }
        return result;
    }
};