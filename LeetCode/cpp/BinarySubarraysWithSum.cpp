class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int numSubarraysWithSum(vector<int> &nums, int goal)
    {
        unordered_map<int, int> count;
        int sum = 0, result = 0;

        for (int num : nums)
        {
            count[sum]++;
            sum += num;
            result += count[sum - goal];
        }

        return result;
    }
};

/*
Explaination:
1. We are given an array of integers nums and an integer goal.
2. We have to find the number of non-empty subarrays with a sum goal.
3. We will use a hashmap to store the count of the sum of the subarray.
4. We will iterate over the array and calculate the sum of the subarray.
5. We will increment the count of the sum in the hashmap.
6. We will increment the result by the count of the sum - goal in the hashmap.
7. Finally, we will return the result.
*/

// Optimal Solution
class Solution {
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        auto helper = [&](int x) {
            if (x < 0)
                return 0;
            int l = 0;
            int sum = 0;
            int count = 0;
            for (int r = 0; r < n; r++) {
                sum += nums[r];
                while (sum > x) {
                    sum -= nums[l++];
                }
                count += (r-l+1);
            }
            return count;
        };
        return helper(goal) - helper(goal-1);
    }
};

/*
Explanation:
1. We are given an array of integers nums and an integer goal.
2. We have to find the number of non-empty subarrays with a sum goal.
3. We will define a helper function that will take an integer x as an argument.
4. The helper function will return the count of the subarrays with a sum less than or equal to x.
5. We will return the difference between the count of the subarrays with a sum equal to goal and the count of the subarrays with a sum equal to goal-1.
6. We will calculate the count of the subarrays with a sum less than or equal to x by using the sliding window technique.
7. We will iterate over the array and calculate the sum of the subarray.
8. We will increment the count by the length of the subarray.
9. Finally, we will return the count.

Last Line: helper(goal) - helper(goal-1) will return the count of the subarrays with a sum equal to goal.
Reason: helper(goal) will return the count of the subarrays with a sum less than or equal to goal. helper(goal-1) will return the count of the subarrays with a sum less than or equal to goal-1. So, the difference between the two will give the count of the subarrays with a sum equal to goal.
*/