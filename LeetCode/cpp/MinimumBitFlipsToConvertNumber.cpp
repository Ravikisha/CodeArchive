class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int minBitFlips(int start, int goal)
    {
        int ans = start ^ goal;
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (ans & (1 << i))
                count++;
        }
        return count;
    }
};