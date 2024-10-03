// Prefix Sum + Hash Map
class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        // Calculate the total sum of the array
        int k = accumulate(nums.begin(), nums.end(), 0LL) % p;
        
        // If the total sum is divisible by p, return 0
        if(k == 0) return 0;
        
        // If the total sum is less than p, return -1
        unordered_map<int, int> lastidx;
        int ans = n;
        int runsum = 0;
        
        lastidx[0] = -1;
        // Calculate the prefix sum of the array
        for(int i = 0; i < n; ++i){
            runsum = (runsum+nums[i])%p;
            if(lastidx.count((runsum-k+p)%p)){
                ans = min(ans, i - lastidx[(runsum-k+p)%p]);
            }
            lastidx[runsum] = i;
        }
        
        return (ans == n) ? -1 : ans;
    }
};

/*
Example:
Input: nums = [3,1,4,2], p = 6
Output: 1

Explanation:
1. The total sum of the array is 3 + 1 + 4 + 2 = 10.
2. The remainder of the total sum divided by p is 10 % 6 = 4.
3. The prefix sum of the array is [3, 4, 8, 10].
4. The prefix sum of the array modulo p is [3, 4, 2, 4].
5. if we remove the subarray [4], the sum of the remaining elements is 3 + 1 + 2 = 6.
*/