class Solution {
    // Time Complexity: O(n+m)
    // Space Complexity: O(n+m)
public:
    Solution(){
        ios_base::sync_with_stdio(false); cin.tie(NULL);
    }
    string mergeAlternately(string word1, string word2) {
        int index = 0;
        string result = "";
        while(index < word1.size() && index < word2.size()){
            result += word1[index];
            result += word2[index];
            index++;
        }
        while(index < word1.size()){
            result += word1[index];
            index++;
        }
        while(index < word2.size()){
            result += word2[index];
            index++;
        }

        return result;
    }
};