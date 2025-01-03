class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        int prev1 = 1;
        int prev2 = 0;
        for (int i = 2; i <= n; i++)
        {
            int result = prev1 + prev2;
            prev2 = prev1;
            prev1 = result;
        }
        return prev1;
    }
};