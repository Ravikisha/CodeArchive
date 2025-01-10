class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int hammingWeight(int n)
    {
        int count = 0;
        while (n > 0)
        {
            count += n % 2;
            n /= 2;
        }
        return count;
    }
};