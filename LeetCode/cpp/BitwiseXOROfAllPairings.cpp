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