class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int longest = 0;
        int n = nums.size();
        if(n == 0) return n;
        
        for(int ele: uset){
            if(uset.find(ele -1) == uset.end()){
                int count = 1;
                int x = ele;
                while(uset.find(x +1) != uset.end()){
                    x = x+1;
                    count++;
                }
                longest = max(count, longest);
            }
        }
        return longest;
    }
};