class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int xorValue = 0;
        if (nums2.size() % 2 == 1)
        {
            for (int num1 : nums1)
            {
                xorValue ^= num1;
            }
        }
        if (nums1.size() % 2 == 1)
        {
            for (int num2 : nums2)
            {
                xorValue ^= num2;
            }
        }

        return xorValue;
    }
};

/*
Explanation:
Given two arrays of integers, nums1 and nums2, we want to find the bitwise XOR of all the pairings of the two arrays. We can do this by iterating through the two arrays and XORing the elements together. If the size of one of the arrays is odd, we need to XOR the remaining element with the result. Finally, we return the result.

if the size of nums2 is odd, we iterate through nums1 and XOR all the elements together.
reason:
nums1 = [1, 2, 3]
nums2 = [4, 5]

combinations:
1 ^ 4 = 5
1 ^ 5 = 4
2 ^ 4 = 6
2 ^ 5 = 7
3 ^ 4 = 7
3 ^ 5 = 6

we can see that the nums2 has an even number of elements, that shows every number in nums1 participates in the XOR operations of multiple of 2 times. So, we don't need to consider the odd number of elements in nums1.
*/