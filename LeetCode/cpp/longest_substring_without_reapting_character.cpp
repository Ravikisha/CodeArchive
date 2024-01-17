class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            int j = i;
            int temp = 0;
            int arr[256] = {0};
            while (j < s.size() && arr[s[j]] == 0) {
                arr[s[j]] = 1;
                temp++;
                j++;
            }
            if (temp > count) {
                count = temp;
            }
        }
        return count;
    }
};