class Solution {
    // Time Complexity: O(logn)
    // Space Complexity: O(1)
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size() -1;
        int low = 0;
        while (low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return -1;
    }
};