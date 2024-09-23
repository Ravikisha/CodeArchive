// Hashing Solution
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> f;

        for(auto i : nums){
            ++f[i];
        }

        for(auto i : f){
            if(i.second > nums.size() / 2){
                return i.first;
            }
        }

        return 0;
    }
};

// Optimal Solution
// Moore's Voting algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = -1;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                candidate = nums[i];
                count = 1;
            }else if(nums[i] == candidate){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};