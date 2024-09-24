// better approach
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 1;
        }
        // find minmax
        map<int, int> m;
        int maxnum = INT_MIN;
        int minnum = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = 1;
            if (nums[i] > maxnum)
            {
                maxnum = nums[i];
            }
            if (nums[i] < minnum)
            {
                minnum = nums[i];
            }
        }
        // find min positive
        if (maxnum <= 0)
        {
            return 1;
        }
        if (minnum <= 0)
        {
            minnum = 1;
        }
        if (minnum > 1)
        {
            return 1;
        }
        for (int i = minnum; i <= maxnum; i++)
        {
            if (m[i] == 0)
            {
                return i;
            }
        }
        return maxnum + 1;
    }
};

// Less Complex Solution
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        for(int i=1;i<=nums.size()+1;i++){
            if(uset.find(i) == uset.end()) return i;
        }
        return 1;
    }
};

// Optimized Solution
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        // put each number in its right place
        for(int i=0;i<n;i++){
            while(nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i] != i+1){
                return i+1;
            }
        }
        return n+1;
    }
};

/*
In this solution, we are finding the first missing positive number in the array. We are using the cyclic sort algorithm to solve this problem. We are iterating over the array and putting each number in its right place. We are swapping the numbers until the number is in the range of 1 to n and the number is not equal to the number at the index nums[i]-1. After putting each number in its right place, we are iterating over the array and checking if the number is not equal to i+1, then we are returning i+1. If all the numbers are in the right place, then we are returning n+1.

Example:
nums = [3, 4, -1, 1]

Now we change all negative numbers to 0
nums = [3, 4, 0, 1]

Now we apply the cyclic sort algorithm
Iteration 1:
i = 0
nums = [0, 4, 3, 1]

Iteration 2:
i = 1
nums = [0, 1, 3, 4]

Iteration 3:
i = 2

Iteration 4:
i = 3

Now we iterate over the array and check if the number is not equal to i+1, then we return i+1. In this case, all the numbers are in the right place, so we return n+1.

Time Complexity: O(n)
Space Complexity: O(1)

*/