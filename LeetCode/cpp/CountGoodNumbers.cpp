class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    // Constant for modular arithmetic
    const int m = 1000000007;

    // Recursive function to calculate (x^y) % m using modular exponentiation
    long long f(long long x, long long y)
    {
        if (y == 0) // Base case: x^0 = 1
            return 1;
        if (y == 1) // Base case: x^1 = x
            return x;

        // Recursive step: calculate (x^(y/2)) % m and store in s
        long long s = f(x, y / 2);

        // If y is odd, multiply one more x to the result and take mod m
        if (y & 1)
        {
            return s * s % m * x % m;
        }
        // If y is even, we can return s * s % m directly
        else
        {
            return s * s % m;
        }
    }

    // Main function to calculate the count of good numbers of length n
    int countGoodNumbers(long long n)
    {
        if (n == 1) // If length is 1, only the five even numbers can be used
            return 5;

        // Calculate (5^((n + 1) / 2)) % m for positions that are even
        // Calculate (4^(n / 2)) % m for positions that are odd
        // Multiply both and return mod m
        return f(5, (n + 1) / 2) * f(4, n / 2) % m;
    }
};
