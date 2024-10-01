class Solution {
    // Time Complexity: O(logn)
    // Space Complexity: O(1)
public:
    bool search(vector<int>& nums, int target) {
      int n = nums.size();
        int low = 0, high = n-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target) return true;
            if(nums[low] < nums[mid]){
                if(nums[low] <= target && target < nums[mid]){
                    high = mid -1;
                }else{
                    low = mid+1;
                }
            }
            else if(nums[low] > nums[mid]){
                if(nums[mid] < target && target <= nums[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
            else low++;
        }
        return false;  
    }
};

/*
Explanation:
1. If nums[low] < nums[mid], then the left half must be sorted.
    a. If nums[low] <= target < nums[mid], then the target must be in the left half.
    b. Otherwise, the target must be in the right half.
2. If nums[low] > nums[mid], then the right half must be sorted.
    a. If nums[mid] < target <= nums[high], then the target must be in the right half.
    b. Otherwise, the target must be in the left half.
3. If nums[low] == nums[mid], then we can't decide which half is sorted, so we just move low to the next element.
*/