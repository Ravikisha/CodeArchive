class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curMax = 0, tmp; 
        
        for(int i = arr.size() - 1; i >= 0; i--){
            tmp = arr[i];
            if(i == arr.size() - 1){
                arr[i] = -1;
            }else{
                arr[i] = curMax;
            }
            curMax = max(curMax, tmp);
        }
        
        return arr;
    }
};