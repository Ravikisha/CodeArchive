class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> uset;
        int l = 0;
        for(int r=0;r<nums.size();r++){
            if(r - l > k){
                uset.erase(nums[l]);
                l++;
            }
            if(uset.find(nums[r]) != uset.end()){
                return true;
            }
            uset.insert(nums[r]);
        }
        return false;
    }
};

/*
Explaination:
1. We use a set to store the elements.
2. We use two pointers l and r to keep track of the window.
3. We iterate through the array and check if the difference between r and l is greater than k.
4. If it is, we remove the element at l and increment l.
5. We check if the element at r is present in the set.
6. If it is, we return true.
7. Finally, we insert the element at r into the set.
8. If we don't find any duplicates, we return false.
*/