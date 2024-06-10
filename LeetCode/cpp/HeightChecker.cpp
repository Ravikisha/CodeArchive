class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int len =heights.size();
        vector<int> order=heights;
        sort(order.begin(), order.end());
        int count =0;
        for(int i=0;i<len;i++){
            if(heights[i]!=order[i])
                count++;
        }
        return count;
    }
};