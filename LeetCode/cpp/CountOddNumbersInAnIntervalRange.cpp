class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int countOdds(int low, int high)
    {
        int cnt = (high - low) / 2;

        if (low & 1 || high & 1)
            cnt++;

        return cnt;
    }
};