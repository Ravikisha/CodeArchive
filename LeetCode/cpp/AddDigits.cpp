class Solution
{
    // Time Complexity: O(1)
    // Space Complexity: O(1)
public:
    int addDigits(int num)
    {
        if (num == 0)
            return 0;
        if (num % 9 == 0)
            return 9;
        return num % 9;
    }
};