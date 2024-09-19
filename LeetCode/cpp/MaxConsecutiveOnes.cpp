class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 1){
                count = 0;
            }else{
                count++;
            }
            if(maxCount < count) maxCount = count;
        }
        return maxCount;
    }
};