class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int l = 0, h = n-1;
        while(l < h){
            int area = (h-l) * min(height[l], height[h]);
            res = max(res, area);

            if(height[l] < height[h]) l++;
            else h--;
        }
        return res;
    }
};