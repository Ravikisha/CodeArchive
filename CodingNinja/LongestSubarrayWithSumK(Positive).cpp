// Two Pointer approach for only positive numbers
int longestSubarrayWithSumK(vector<int> a, long long k) {
    long long sum = a[0];
    int maxLen = 0;
    int low=0, high=0;
    int n = a.size();
    while(high < n){
        while(low <= high && sum > k){
            sum -= a[low];
            low++;
        }
        if(sum == k){
            maxLen = max(maxLen, high - low +1);
        }
        high++;
        if(high < n){
            sum += a[high];
        }
    } 
    return maxLen;
}