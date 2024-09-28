class Solution {
    // Time Complexity: O(log(n-k) + k)
    // Space Complexity: O(1)
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l=0, r=n-k;
        while(l < r){
            int m= l + (r-l)/2;
            if(x - arr[m] > arr[m+k] -x){
                l = m+1;
            }else{
                r = m;
            }
        }
        return vector<int>(arr.begin() + l, arr.begin() + l + k);
    }
};