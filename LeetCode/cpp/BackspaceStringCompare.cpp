class Solution {
    // Time Complexity: O(m+n)
    // Space Complexity: O(1)
public:
    bool backspaceCompare(string s, string t) {
        int curS = s.size()-1, curT = t.size()-1;
        int skipS = 0, skipT =0;
        // if the current character is #, we need to skip the next character
        // if two string ends concurrently, we return true
        while(curS >= 0 || curT >= 0){
            while(curS >= 0){
                if(s[curS] == '#'){skipS++;curS--;}
                else if(skipS >0){skipS--;curS--;}
                else break;
            }
            while(curT >= 0){
                if(t[curT] == '#'){skipT++;curT--;}
                else if(skipT > 0) {skipT--;curT--;}
                else break;
            }
            if(curS >= 0 && curT >= 0 && s[curS] != t[curT]) return false;
            // one string ends earlier than the other
            if((curS >= 0) != (curT >= 0)) return false;
            curS--;curT--;
        }
        
        return true;
    }
};