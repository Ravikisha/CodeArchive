// Prefix Sum + Hash Table
class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int minSubarray(vector<int> &nums, int p)
    {
        // Find the total sum of the array
        int total = reduce(nums.begin(), nums.end(), 0);
        // Find the remainder of the total sum divided by p
        int remain = total % p;
        // If the remainder is 0, return 0
        if (remain == 0)
            return 0;
        // Initialize the result to the size of the array
        int res = nums.size();
        // Initialize the current sum to 0
        int cur_sum = 0;

        // Create a hash table to store the prefix sum
        unordered_map<int, int> umap;
        // Initialize the prefix sum to -1
        umap[0] = -1;
        // Traverse the array
        for (int i = 0; i < nums.size(); i++)
        {
            // Calculate the current sum
            cur_sum = (cur_sum + nums[i]) % p;
            // Calculate the prefix sum
            int prefix = (cur_sum - remain + p) % p;
            // If the prefix sum is in the hash table
            if (umap[prefix])
            {
                // Calculate the length of the subarray
                int length = i - umap[prefix];
                // Update the result
                res = min(res, length);
            }
            // Update the hash table
            umap[cur_sum] = i;
        }
        // If the result is equal to the size of the array, return -1
        return res == nums.size() ? -1 : res;
    }
};

/*
Example:
Input: nums = [3,1,4,2], p = 6
Output: 1

Explanation:
1. The total sum of the array is 3 + 1 + 4 + 2 = 10.
2. The remainder of the total sum divided by p is 10 % 6 = 4.
3. The prefix sum of the array is [3, 4, 8, 10].
4. The prefix sum of the array modulo p is [3, 4, 2, 4].
5. if we remove the subarray [4], the sum of the remaining elements is 3 + 1 + 2 = 6.
*/