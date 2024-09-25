class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int idx1=0,idx2=0,arrIdx1=0,arrIdx2=0;
        // loop through the two arrays
        while(arrIdx1 < word1.size() && arrIdx2 < word2.size()){
            // if the characters are not equal, break
            if(word1[arrIdx1][idx1] != word2[arrIdx2][idx2]) break;
            ++idx1;
            // if the current word ends in word1, move to the next word
            if(idx1 == word1[arrIdx1].size()){
                arrIdx1++;
                idx1 = 0;
            }
            ++idx2;
            // if the current word ends in word2, move to the next word
            if(idx2 == word2[arrIdx2].size()){
                arrIdx2++;
                idx2 = 0;
            }
        }
        // if both arrays are exhausted, return true
        return (arrIdx1 == word1.size() && arrIdx2 == word2.size());
    }
};