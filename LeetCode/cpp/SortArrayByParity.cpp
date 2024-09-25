class Solution {
    // Time Complexity: O(n), Space Complexity: O(1)
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        // if(n <= 1) return nums;
        // int low = 0, high = n-1;
        // while(low < high){
        //     if(nums[low] % 2 != 0 ){
        //         swap(nums[low++], nums[high--]);
        //     }
        // }
        // return nums;
        int low = 0;
        for(int i=0;i<n;i++){
            if(nums[i] % 2 == 0){
                swap(nums[low++], nums[i]);
            }
        }
        return nums;
    }
};