class Solution
{
    // Time Complexity: O(log(dividend/divisor))
    // Space Complexity: O(1)
public:
    int divide(int dividend, int divisor)
    {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        // Determine the sign of the result
        bool isPositive = (dividend < 0) == (divisor < 0);

        // Use long long to handle abs(INT_MIN)
        long long n = abs((long long)dividend);
        long long d = abs((long long)divisor);
        long long quotient = 0;

        // Perform the division using bit manipulation
        while (n >= d)
        {
            long long temp = d, multiple = 1;
            while (n >= (temp << 1))
            {
                temp <<= 1;
                multiple <<= 1;
            }
            n -= temp;
            quotient += multiple;
        }

        // Apply the sign and handle overflow
        if (!isPositive)
            quotient = -quotient;

        return quotient > INT_MAX ? INT_MAX : quotient;
    }
};