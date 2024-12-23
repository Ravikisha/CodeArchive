class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int maxScore(string s)
    {
        int ones = 0, n = s.size(), maxSum = 0;
        for (char c : s)
        {
            if (c == '1')
                ones++;
        }
        int leftSum = 0, rightSum = ones;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
                leftSum++;
            else
                rightSum--;
            maxSum = max(maxSum, leftSum + rightSum);
        }
        return maxSum;
    }
};