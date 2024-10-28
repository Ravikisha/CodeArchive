class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(1)
public:
    int myAtoi(string s)
    {
        // Check if string is empty.
        if (s.empty())
        {
            return 0;
        }

        int ans = 0;
        int sign = 1;
        int i = 0;

        // Skip whitespace.
        while (s[i] == ' ' || s[i] == '\t')
        {
            ++i;
        }
        // Check if string is empty after skipping whitespace.
        if (i == s.length())
        {
            return 0;
        }

        // Parse sign.
        if (s[i] == '+')
        {
            ++i;
        }
        else if (s[i] == '-')
        {
            sign = -1;
            ++i;
        }

        // Compute integer.
        for (; i < s.length() && isdigit(s[i]); ++i)
        {
            if (ans > (numeric_limits<int>::max() - (s[i] - '0')) / 10)
            {
                return sign > 0 ? numeric_limits<int>::max() : numeric_limits<int>::min();
            }
            ans *= 10;
            ans += s[i] - '0';
        }

        ans *= sign;
        return ans;
    }
};

class Solution
{
    // Time Complexity: O(n)
    // Space Complexity: O(n)
public:
    int myAtoi(std::string s)
    {
        if (s.empty())
            return 0;
        int index = 0;
        int sign = 1;

        // Helper function to skip whitespace
        while (index < s.size() && isspace(s[index]))
        {
            ++index;
        }

        // Helper function to handle signs
        if (index < s.size() && (s[index] == '+' || s[index] == '-'))
        {
            sign = (s[index] == '-') ? -1 : 1;
            ++index;
        }

        return convertRecursively(s, index, 0, sign);
    }

private:
    int convertRecursively(const std::string &s, int index, int result, int sign)
    {
        if (index >= s.size() || !isdigit(s[index]))
            return result * sign;

        int digit = s[index] - '0';

        // Check overflow before including the digit
        if (result > (std::numeric_limits<int>::max() - digit) / 10)
        {
            return sign == 1 ? std::numeric_limits<int>::max() : std::numeric_limits<int>::min();
        }

        result = result * 10 + digit;

        return convertRecursively(s, index + 1, result, sign);
    }
};