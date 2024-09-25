class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> uset;
        for(int i=0;i<nums.size();i++){
            if(uset.find(nums[i]) != uset.end()){
                return true;
            }else{
                uset.insert(nums[i]);
            }
        }
        return false;
    }
};