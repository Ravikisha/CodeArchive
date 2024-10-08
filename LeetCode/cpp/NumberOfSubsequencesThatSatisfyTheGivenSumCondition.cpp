class Solution {
    // Time Complexity: O(nlogn)
    // Space Complexity: O(n) for power array
public:
    int numSubseq(vector<int>& nums, int target) {
        int res = 0;
        int MOD = 1e9+7;
        int n = nums.size();
        vector<int> power(n, 1);
        
        //precalculate the powers
        for(int i = 1; i < n; ++i){
            power[i] = (power[i-1] << 1) % MOD;
        }

        sort(nums.begin(), nums.end());
        for(int l = 0, r = n-1; l <= r; ){
            if(nums[l] + nums[r] > target){
                //either decrease r or increase l
                --r;
            }else{
                res = (res + power[r-l]) % MOD;
                //either decrease r or increase l
                ++l;
            }
        }
        return res;
    }
};