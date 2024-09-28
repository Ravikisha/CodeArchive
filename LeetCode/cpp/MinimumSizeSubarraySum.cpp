class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minCount = INT_MAX;
        int left=0;
        int sum = 0;
        for(int r=0;r<n;r++){
            sum += nums[r];
            while(sum >= target){
                minCount = min(minCount, r-left+1);
                sum -= nums[left];
                left++;
            }
        }
        return minCount == INT_MAX ? 0 : minCount;
    }
};