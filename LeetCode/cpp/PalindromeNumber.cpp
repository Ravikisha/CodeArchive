// Cpp Solution
class Solution
{
    // Time Complexity: O(log(n))
    // Space Complexity: O(1)
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        long long pali = 0, temp = x;
        while (temp != 0)
        {
            pali = pali * 10 + (temp % 10);
            temp /= 10;
        }
        return pali == x;
    }
};