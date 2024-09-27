class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l=0, r=0, maxLen=0, maxFreq =0;
        int words[26] = {0};
        while(r < n){
            words[s[r] - 'A']++;
            maxFreq = max(maxFreq, words[s[r] - 'A']);
            if(r-l+1 - maxFreq  > k){
                words[s[l++] - 'A']--;
                // maxFreq = 0;
                // for(int i=0;i<26;i++){
                //     maxFreq = max(maxFreq, words[s[i]]);
                // }
                // if((r-l+1) - maxFreq <= k){
                //     maxLen = max(maxLen, r-l+1);
                // }
            }
            maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};