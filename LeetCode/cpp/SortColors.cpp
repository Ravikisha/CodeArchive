// Brute Force Solution
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        map<int, int> counter;
        for (int &num : nums)
        {
            counter[num]++;
        }

        int cur = 0;
        for (auto it = counter.begin(); it != counter.end(); it++)
        {
            while (it->second)
            {
                nums[cur++] = it->first;
                it->second--;
            }
        }
    }
};

// Dutch Flag Algorithm
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low=0,mid=0,high=nums.size()-1;
        while(mid <= high){
            switch(nums[mid]){
                case 0:
                    swap(nums[mid++], nums[low++]);
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(nums[mid], nums[high--]);
                    break;
            }
        }   
    }
};
*/