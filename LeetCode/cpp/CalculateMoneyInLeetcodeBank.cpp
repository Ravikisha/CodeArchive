class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int totalMoney(int n)
    {
        int a = n / 7, b = n % 7;
        return (28 + 28 + 7 * (a - 1)) * a / 2 + (a * 2 + b + 1) * b / 2;
    }
};