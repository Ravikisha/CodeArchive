class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        long long xorNumber = 0;

        // XOR all numbers to find the XOR of the two unique numbers
        for (int num : nums)
        {
            xorNumber ^= num;
        }

        // Find the rightmost set bit (without undefined behavior)
        long long rightMost = xorNumber & -xorNumber;

        int num1 = 0, num2 = 0;

        // Partition the numbers based on the rightmost set bit
        for (int num : nums)
        {
            if (num & rightMost)
            {
                num1 ^= num; // Group where the bit is set
            }
            else
            {
                num2 ^= num; // Group where the bit is not set
            }
        }

        return {num1, num2};
    }
};