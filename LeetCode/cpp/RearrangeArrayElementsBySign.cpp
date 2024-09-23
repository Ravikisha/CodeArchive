class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();

        vector<int> ans(n);

        for(int p = 0; p < n; p++){
            if(nums[p] < 0){
                ans[j] = nums[p];
                j += 2;
            }
            else{
                ans[i] = nums[p];
                i += 2;
            }
        }

        return ans;
    }
};

// Another Approach
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> neg, pos;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] > 0) pos.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        if(pos.size() > neg.size()){
            for(int i=0;i<neg.size();i++){
                nums[2*i] = pos[i];
                nums[2*i+1]=neg[i];
            }
            int index = neg.size()*2;
            for(int i=neg.size(); i< pos.size();i++){
                nums[index++] = pos[i];
            }
        }else{
            for(int i=0;i<pos.size();i++){
                nums[2*i] = pos[i];
                nums[2*i+1]=neg[i];
            }
            int index = pos.size()*2;
            for(int i=pos.size(); i< neg.size();i++){
                nums[index++] = neg[i];
            }
        }
        return nums;
    }
};