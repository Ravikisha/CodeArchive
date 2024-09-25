class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 2;
        if (nums.size() <= 2)
            return nums.size();
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[k - 2])
            {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Example:
Input: nums = [1,1,1,2,2,3]
Iteration 1: nums = [1,1,1,2,2,3], k = 2
Iteration 2: nums = [1,1,2,2,2,3], k = 3
Iteration 3: nums = [1,1,2,2,2,3], k = 4
Iteration 4: nums = [1,1,2,2,3,3], k = 5
Output: 5, nums = [1,1,2,2,3,3]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2, and 3 respectively. It does not matter what you leave beyond the returned k (hence they are underscores).
*/