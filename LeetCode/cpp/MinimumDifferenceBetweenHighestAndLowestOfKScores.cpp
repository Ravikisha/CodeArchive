class Solution {
    // Time Complexity: O(nlogn)
    // Space Complexity: O(1)
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = k-1;
        int ans = INT_MAX;
        while(high < n){
            ans = min(ans, nums[high]-nums[low]);
            low++;
            high++;
        }
        return ans;
    }
};