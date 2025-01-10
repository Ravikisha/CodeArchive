class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    bool isPowerOfTwo(int n)
    {
        return n and !(n & (n - 1LL));
    }
};